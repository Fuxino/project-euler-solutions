-- If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
--
-- Find the sum of all the multiples of 3 or 5 below 1000.
sumMultiples :: (Integral n) => n
sumMultiples = sum(filter p [ n | n <- [1..999] ])
                where p n = n `mod` 3 == 0 || n `mod` 5 == 0

main :: IO ()
main =  do
    let result = sumMultiples
    putStrLn $ "Project Euler, Problem 1\n"
        ++ "Answer: " ++ (show result)
