data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = Node Empty a Empty
addInTree a (Node  r_node val l_node) | a == val = Node  r_node val l_node
                           | a < val = Node (addInTree a r_node) val l_node
                           | otherwise = Node r_node val (addInTree a l_node)

instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node l_node v r_node) = Node (fmap f l_node) (f v) (fmap f r_node)

listToTree :: Ord a => [a] -> Tree a
listToTree = foldr addInTree Empty

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node l_node v r_node) =
    treeToList l_node ++ [v] ++ treeToList r_node

treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort list = treeToList (listToTree list)

instance Foldable Tree where
    foldMap fct Empty = mempty
    foldMap fct (Node l_node v r_node) =
        foldMap fct l_node `mappend` fct v `mappend` foldMap fct r_node
    foldr fct arg Empty = arg
    foldr fct arg (Node l_node v r_node) =
        foldr fct (fct v (foldr fct arg r_node)) l_node