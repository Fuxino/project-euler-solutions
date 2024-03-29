-- The prime factors of 13195 are 5, 7, 13 and 29.  --
-- What is the largest prime factor of the number 600851475143?
import ProjectEuler

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
