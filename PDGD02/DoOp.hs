import Control.Applicative
import Control.Monad
import Data.Char (isDigit)
import Data.Maybe
import System.Environment
import System.Exit

myElem :: Eq a => a -> [a] -> Bool
myElem n [] = False
myElem n [elem] = n == elem
myElem n (first : rest) = (n == first) || myElem n rest

safeDiv :: Int -> Int -> Maybe Int
safeDiv n 0 = Nothing
safeDiv n x = Just (div n x)

safeNth :: [a] -> Int -> Maybe a
safeNth [] n = Nothing
safeNth (f : r) n
  | length r < n = Nothing
  | 0 > n = Nothing
safeNth (f : r) 0 = Just f
safeNth (f : r) n = safeNth r (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc n = fmap (+ 1) n :: Maybe Int

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup n [] = Nothing
myLookup eq ((key, val_str) : rest)
  | eq == key = Just val_str
  | otherwise = myLookup eq rest

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo fct Nothing b = Nothing
maybeDo fct a Nothing = Nothing
maybeDo fct a b = do
  x1 <- a
  fct x1 <$> b

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt str
  | all isDigit str = case reads str of
    [(a, b)] -> Just a
    a -> Nothing
  | otherwise = Nothing

getLineLength :: IO Int
getLineLength = length <$> getLine

printAndGetLength :: String -> IO Int
printAndGetLength str = length str <$ putStrLn str

boxX :: Int -> IO ()
boxX 0 = return ()
boxX height =
  putStr "-"
    >> boxX (height - 1)

printBoxX :: Int -> IO ()
printBoxX height =
  putChar '+'
    >> boxX (height - 2)
    >> putStrLn "+"

boxY :: Int -> IO ()
boxY 0 = return ()
boxY height =
  putStr " "
    >> boxY (height - 1)

printBoxY :: Int -> IO ()
printBoxY height =
  putChar '|'
    >> boxY (height - 2)
    >> putStrLn "|"

printCore :: Int -> Int -> IO ()
printCore 0 n = return ()
printCore height n =
  printBoxY n
    >> printCore (height - 1) n

printBox :: Int -> IO ()
printBox n | n <= 0 = return ()
printBox 1 = putStrLn "++"
printBox height =
  printBoxX (height * 2)
    >> printCore (height - 2) (height * 2)
    >> printBoxX (height * 2)

concatLines :: Int -> IO String
concatLines n | n <= 0 = return ""
concatLines n = concat <$> replicateM n getLine

getInt :: IO (Maybe Int)
getInt = do
  nb <- getLine
  if isNothing (readInt nb)
    then return Nothing
    else return (Just (read nb :: Int))

myNth :: [a] -> Int -> a
myNth [] n = error "error"
myNth (f : r) n
  | length r < n = error "error"
  | 0 > n = error "error"
myNth (f : r) 0 = f
myNth (f : r) n = myNth r (n - 1)

doOpErrorHandling :: [av] -> IO ()
doOpErrorHandling av = when (length av /= 3) $ exitWith (ExitFailure 84)

doOp :: String -> Int -> Int -> Int
doOp "+" nb1 nb2 = nb1 + nb2
doOp "-" nb1 nb2 = nb1 - nb2
doOp "*" nb1 nb2 = nb1 * nb2
doOp "/" nb1 0 = -2934
doOp "/" nb1 nb2 = nb1 `div` nb2
doOp "%" nb1 0 = -2934
doOp "%" nb1 nb2 = nb1 `mod` nb2
doOp _ nb1 nb2 = -2934

main :: IO Integer
main = do
  args <- getArgs
  doOpErrorHandling args
  let nb1 = read (head args) :: Int
  let nb2 = read (myNth args 2) :: Int
  let result = doOp (myNth args 1) nb1 nb2
  when (result == (-2934)) $ exitWith (ExitFailure 84)
  print result
  return 0