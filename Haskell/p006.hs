-- The sum of the squares of the first ten natural numbers is,
--
-- 1^2 + 2^2 + ... + 10^2 = 385
--
-- The square of the sum of the first ten natural numbers is,
--
-- (1 + 2 + ... + 10)^2 = 55^2 = 3025
--
-- Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
--
--Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

sumSquareDiff :: Integer -> Integer
sumSquareDiff n = (sum [1..n]^2) - (sum $ map (^2) [1..n])

main = do
    let result = sumSquareDiff 100
    putStrLn $ "Project Euler, Problem 6\n"
        ++ "Answer: " ++ (show result)
