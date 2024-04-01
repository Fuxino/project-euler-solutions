-- 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
--
-- What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

lcmm :: (Integral n) => [n] -> n
lcmm values
    | length values == 2    = lcm (head values) (last values)
    | otherwise             = lcm (head values) (lcmm (tail values))

main = do
    let result = lcmm [1..20]
    putStrLn $ "Project Euler, Problem 5\n"
        ++ "Answer: " ++ (show result)
