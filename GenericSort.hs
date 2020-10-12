import Data.List (sortBy)
import Data.Ord (comparing)

-- MERGESORT
--function to execute mergesort
msort :: Ord a => [a] -> [a]
-- if the list is empty, return an empty list
msort [] = []
-- if there is only one element, the list is sorted
msort [x] = [x]
-- use merge function to combine two smaller sorted lists
-- recursively call sort function for each smaller list
msort xs = merge (msort ys) (msort zs)
  -- use split function split xs in half, then save as a tuple
  where (ys,zs) = split xs

-- Function to split a list into two halves in a tuple of lists
split :: [a] -> ([a],[a])
-- first element in tuple is the first half of the list
-- second element in tuple is the second half of the list
split xs = (take len xs, drop len xs)
  -- define len name to be half the length of the list
  where len = div (length xs) 2

-- function to merge sorted sublists
merge :: Ord a => [a] -> [a] -> [a]
-- if the ys list is empty, return xs
merge xs [] = xs
-- if the xs list is empty, return ys
merge [] ys = ys
-- merge two nonempty lists, checking the first element of each
merge (x:xs) (y:ys)
  -- if the first element is smaller than the second element
  -- place the first element before the second, then recursively
  -- call merge with the next element in xs
  | x <= y    = x : merge xs (y:ys)
  -- if the second element is larger, place is before
  -- the first element, then recursively call merge with
  -- the next element in ys
  | otherwise = y : merge (x:xs) ys

-- defining data type
data Person = Person { name :: String  
                     , age :: Int  
                     } deriving (Eq, Show)   

-- declares an order that goes compares by name
instance Ord Person where
  -- compares the names
  p <= q = name p <= name q


-- creating a list of people
somePeople = [Person "Hal" 20, Person "Susann" 31, Person "Dwight" 19, Person "Kassandra" 21, Person "Lawrence" 25, Person "Cindy" 22, Person "Cory" 27, Person "Mac" 19, Person "Romana" 27, Person "Doretha" 32, Person "Danna" 20, Person "Zara" 23, Person "Rosalyn" 26, Person "Risa" 24, Person "Benny" 28, Person "Juan" 33, Person "Natalie" 25]

-- setting up the main function
main = do 
-- providing the unsorted float array
  putStrLn "Inputted Float Array: [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]"
-- calling on the msort function
  putStr "Sorted Array Using Merge Sort: "
  print $ msort [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, -876.22, 467.73, 62.26]

-- providing unsorted person array
  putStrLn "Inputted Person Array: [Person Hal 20, Person Susann 31, Person Dwight 19, Person Kassandra 21, Person Lawrence 25, Person Cindy 22, Person Cory 27, Person Mac 19, Person Romana 27, Person Doretha 32, Person Danna 20, Person Zara 23, Person Rosalyn 26, Person Risa 24, Person Benny 28, Person Juan 33, Person Natalie 25]"

-- calling on the msort function
  putStr "Sorted Person Array Based on Name: "
  print $ msort somePeople
  -- another way to solve: print $ sortBy (comparing name) somePeople

-- calling on the sortBy function from the Data.List module and comparing from Data.Ord to sort based on age
  putStr "Sorted Person Array Based on Age: "
-- using the flip function to reverse from ascending to descending when comparing by age 
  print $ sortBy (flip (comparing (age))) somePeople
