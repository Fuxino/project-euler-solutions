module ProjectEuler
( isPrime
) where

isPrime :: (Integral n) => n -> Bool
isPrime 1 = False
isPrime 2 = True
isPrime 3 = True
isPrime n =
    n `mod` 2 /= 0 && n `mod` 3 /= 0 && null [ x | x <- candidates, n `mod` x == 0 || n `mod` (x+2) == 0 ]
    where candidates = [5,11..limit]
          limit = floor(sqrt(fromIntegral n)) + 1
