fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

main = do
    q <- read <$> getLine :: IO Int
    print $ fibs !! q

