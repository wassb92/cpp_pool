mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs a
  | a > 0 = a
  | otherwise = - a

myMin :: Int -> Int -> Int
myMin a b
  | a > b = b
  | otherwise = a

myMax :: Int -> Int -> Int
myMax a b
  | a < b = b
  | otherwise = a

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "error"
myHead (f : r) = f

myTail :: [a] -> [a]
myTail [] = error "error"
myTail (f : r) = r

myLength :: [a] -> Int
myLength [] = 0
myLength (f : r) = myLength r + 1

myNth :: [a] -> Int -> a
myNth [] n = error "error"
myNth (f : r) n
  | myLength r < n = error "error"
  | 0 > n = error "error"
myNth (f : r) 0 = f
myNth (f : r) n = myNth r (n - 1)

myTake :: Int -> [a] -> [a]
myTake n a
  | myLength a < n = a
myTake 0 _ = []
myTake n [] = []
myTake n (first : rest) = first : myTake (n -1) rest

myDrop :: Int -> [a] -> [a]
myDrop 0 a = a
myDrop n a
  | myLength a < n = []
myDrop n [] = []
myDrop n (first : rest) = myDrop (n - 1) rest

myAppend :: [a] -> [a] -> [a]
myAppend [] [] = []
myAppend [] b = b
myAppend a [] = a
myAppend (first : rest) b = first : myAppend rest b

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (first : rest) = myAppend (myReverse rest) [first]

myInit :: [a] -> [a]
myInit [] = error "error"
myInit a
  | myLength a == 1 = []
myInit (first : rest) = first : myInit rest

myLast :: [a] -> a
myLast [] = error "error"
myLast [a] = a
myLast (_ : rest) = myLast rest

myZip :: [a] -> [b] -> [(a, b)]
myZip [] a = []
myZip b [] = []
myZip (f_x : r_x) (f_y : r_y) = (f_x, f_y) : myZip r_x r_y

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((x, y) : rest) = let (a, b) = myUnzip rest in (x : a, y : b)

myMap :: (a -> b) -> [a] -> [b]
myMap f [] = []
myMap fct (first : rest) = fct first : myMap fct rest