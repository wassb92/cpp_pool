import Control.Monad (when)
import Data.Char (isDigit)
import Data.List (unfoldr)
import System.Environment (getArgs)
import System.Exit (ExitCode (ExitFailure), exitSuccess, exitWith)

-- Error handling

isOperation :: [String] -> Bool
isOperation (x : rest) =
  (x == "sa" || x == "sb" || x == "sc" ||
  x == "pa" || x ==   "pb" ||
  x == "ra" || x == "rb" || x == "rr" || x == "rra" || x == "rrb")
  && isOperation rest
isOperation op = True

errorHandling :: [Int] -> [String] -> Bool
errorHandling [] _ = True
errorHandling av op = not (isOperation op)

-- !Error handling

-- Lib / Utils
strToWordArray :: Eq a => a -> [a] -> [[a]]
strToWordArray del = unfoldr sep
  where
    sep [] = Nothing
    sep list = Just . fmap (drop 1) . break (== del) $ list

atoiList :: [String] -> [Int]
atoiList [] = []
atoiList av
  | all (all isDigit) av = map read av
  | otherwise = []

getLast :: [Int] -> Int
getLast [] = 0
getLast [x] = x
getLast (_ : xs) = getLast xs

-- !Lib / Utils

-- Operation
swap :: [Int] -> [Int]
swap [] = []
swap [x] = [x]
swap (first : second : rest) = second : first : rest

rotate :: [Int] -> [Int]
rotate [] = []
rotate xs = zipWith const (drop 1 (cycle xs)) xs

rotateR :: [Int] -> [Int]
rotateR [] = []
rotateR xs = last xs : init xs

sa :: [Int] -> [Int] -> ([Int], [Int])
sa a list = (swap a, list)

sb :: [Int] -> [Int] -> ([Int], [Int])
sb list b = (list, swap b)

sc :: [Int] -> [Int] -> ([Int], [Int])
sc a b = (swap a, swap b)

pa :: [Int] -> [Int] -> ([Int], [Int])
pa a (b : bs) = (b : a, bs)
pa _ _ = ([], [])

pb :: [Int] -> [Int] -> ([Int], [Int])
pb (a : as) b = (as, a : b)
pb _ _ = ([], [])

ra :: [Int] -> [Int] -> ([Int], [Int])
ra a list = (rotate a, list)

rb :: [Int] -> [Int] -> ([Int], [Int])
rb list b = (list, rotate b)

rr :: [Int] -> [Int] -> ([Int], [Int])
rr a b = (rotate a, rotate b)

rra :: [Int] -> [Int] -> ([Int], [Int])
rra a list = (rotateR a, list)

rrb :: [Int] -> [Int] -> ([Int], [Int])
rrb list b = (list, rotateR b)

rrr :: [Int] -> [Int] -> ([Int], [Int])
rrr a b = (rotateR a, rotateR b)

-- !Operation

-- Execute Operation

doOpRotate :: String -> [Int] -> [Int] -> ([Int], [Int])
doOpRotate "ra" a b = ra a b
doOpRotate "rb" a b = rb a b
doOpRotate "rr" a b = rr a b
doOpRotate "rra" a b = rra a b
doOpRotate "rrb" a b = rrb a b
doOpRotate "rrr" a b = rrr a b
doOpRotate elseOp a b = ([], [])

doOp :: String -> [Int] -> [Int] -> ([Int], [Int])
doOp "sa" a b = sa a b
doOp "sb" a b = sb a b
doOp "sc" a b = sc a b
doOp "pa" a b = pa a b
doOp "pb" a b = pb a b
doOp op a b = doOpRotate op a b

execFunction :: [String] -> ([Int], [Int]) -> [([Int], [Int])]
execFunction (x : xs) (a, b) =
  doOp x a b : execFunction xs (t, ts)
  where (t, ts) = doOp x a b
execFunction [] (a, b) = [([], [])]

-- !Execute Operation

-- Check Output
sorted :: (Ord a) => [a] -> Bool
sorted [] = True
sorted [x] = True
sorted [x, y] = x <= y
sorted (x:y:xs) = (x <= y) && sorted (y:xs)

isPushswap :: ([Int],[Int]) -> Bool
isPushswap (a, []) = sorted a
isPushswap (a, b) = False

-- !Check Output


main :: IO Integer
main = do
  av <- getArgs
  line <- getLine
  let listA = atoiList av
  let operations = strToWordArray ' ' line
  when (sorted listA) exitSuccess
  when (errorHandling listA operations) $ exitWith (ExitFailure 84)
  let getAllTuples = execFunction operations (listA, [])
  let tuple = getAllTuples !! (length getAllTuples - 2)
  if isPushswap tuple then putStrLn "OK" else putStr "KO: " >> print tuple
  return 0