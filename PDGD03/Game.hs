{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
{-# OPTIONS_GHC -Wno-overlapping-patterns #-}

data Item = Sword | Bow | MagicWand deriving (Eq)

instance Show Item where
  show Sword = "sword"
  show Bow = "bow"
  show MagicWand = "magic wand"

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving (Eq)

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = Just createMummy
create "doomed archer" = Just createArcher
create "dead knight" = Just createKnight
create "witch" = Just createWitch
create "sorceress" = Just createSorceress
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip item Mummy = Nothing
equip item (Skeleton _) = Just (Skeleton item)
equip item (Witch _) = Just (Witch (Just item))

instance Show Mob where
  show Mummy = "mummy"
  show (Skeleton Bow) = "doomed archer"
  show (Skeleton Sword) = "dead knight"
  show (Skeleton elseItem) = "skeleton holding a " ++ show elseItem
  show (Witch Nothing) = "witch"
  show (Witch (Just MagicWand)) = "sorceress"
  show (Witch elseItem) = "witch holding a " ++ show elseItem

class HasItem a where
  getItem :: a -> Maybe Item
  hasItem :: a -> Bool

instance HasItem Mob where
  getItem Mummy = Nothing
  getItem (Skeleton item) = Just item
  getItem (Witch Nothing) = Nothing
  getItem (Witch item) = item
  getItem _ = Nothing
  hasItem Mummy = False
  hasItem (Skeleton a) = True
  hasItem (Witch Nothing) = False
  hasItem (Witch a) = True
