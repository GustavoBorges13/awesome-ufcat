--Nome: Fulano de tal
--Matricula: XXXXXXXX

--Questão 1
{-- 
    O resultado codigo será realmente 22, e isto se deve, a questão da recursividade que é envolvida no programa
    pois como podemos notar no exeemplo abaixo o y sempre ira receber o valor da direita para esquerda da lista,
    enquanto o x vai acumulando os valores somados ao decorrer do processo.
    Ao decorrer do processo é possivel notar que o y não ira interferir no resultado final ele só ficara responsavel
    pela a recursividade do processo que possui sua vida findando no momento que o y não tiver mais valor para receber,
    enquanto o x por ser o acumulador ira interferir diretamente no valor final. 
    

    P0 -> foldr (\y -> \x -> x + 5) 2 [1,14,27,35]
    P1 -> foldr (35 -> 2 -> 2 + 5) 2 [1,14,27,35]
    P2 -> foldr (27 -> 7 -> 7 + 5) 2 [1,14,27,35]
    P3 -> foldr (14 -> 12 -> 12 + 5) 2 [1,14,27,35]
    P4 -> foldr (1 -> 17 -> 17 + 5) 2 [1,14,27,35]
    Resultado = 22
--}

--Questão 2
--main = do print(minEmax 9 2 5)
minEmax :: Int -> Int -> Int -> (Int, Int)
minEmax x y z
 | (x > y) && (y > z) = (x, z)
 | (y > x) && (x > z) = (y, z)
 | (z > x) && (x > y) = (z, y)
 | (x > z) && (z > y) = (x, y)
 | (y > z) && (z > x) = (y, x)
 | otherwise = (x, z)
 
--Questão 3
--main = do print(euclides [(3, 6), (7, 9)])

euclides :: [(Float, Float)] -> [Float]
euclides [] = []
euclides (x:xs) = sqrt (((fst x + 0)^2) + ((snd x + 0)^2)) :  euclides xs

--Questão 4
--main = do print(consecutivo [1, 1, 2, 3, 3, 4, 4, 4, 5])
--main = do print(consecutivo "aaaabccaadeeee")


consecutivo':: Ord a => Int -> [a] -> [(Int,a)]
consecutivo' num [x] = [(num,x)]
consecutivo' num (x:xs)  
 | x == head(xs) = consecutivo' (num+1) xs
 | otherwise = (num, x) : consecutivo' 1 xs

consecutivo :: Ord a => [a] -> [(Int, a)]
consecutivo [] = []
consecutivo (xs) = (consecutivo' 1 (xs))