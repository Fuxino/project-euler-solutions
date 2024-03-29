-- The prime factors of 13195 are 5, 7, 13 and 29.  --
-- What is the largest prime factor of the number 600851475143?

isPrime :: (Integral n) => n -> Bool
isPrime 1 = False
isPrime 2 = True
isPrime 3 = True
isPrime n =
    n `mod` 2 /= 0 && n `mod` 3 /= 0 && null [ x | x <- candidates, n `mod` x == 0 || n `mod` (x+2) == 0 ]
    where candidates = [5,11..limit]
          limit = floor(sqrt(fromIntegral n)) + 1

maxPrimeFactor :: (Integral n) => n -> n
maxPrimeFactor n
    | isPrime n         = n         
    | n `mod` 2 == 0    = maxPrimeFactor $ fromIntegral n `div` 2
    | otherwise         = maxPrimeFactor $ fromIntegral n `div` head [i | i <- [3,5..], n `mod` i == 0 && isPrime i]

main :: IO ()
main = do
    let result = maxPrimeFactor 600851475143
    putStrLn $ "Project Euler, Problem 3\n"
        ++ "Answer: " ++ (show result)
