-- By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
--
-- What is the 10 001st prime number?
--
import ProjectEuler (isPrime)

nthPrime :: (Integral a) => Int -> a
nthPrime n = last $ take n [ x | x <- [1..], isPrime x ]

main = do
    let result = nthPrime 10001
    putStrLn $ "Project Euler, Problem 7\n"
        ++ "Answer: " ++ (show result)
