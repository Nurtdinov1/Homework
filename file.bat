chcp 1251
mkdir "1 курс"\"1 семестр"\"Алгебра и геометрия" 
cd "1 курс"\"1 семестр"
mkdir "Мат анализ"
cd "1 курс"\"1 семестр"
mkdir "Основы программирования"
cd "1 курс"\"1 семестр"
mkdir "АВС"

cd ..\
mkdir "2 семестр"\"Мат анализ"
mkdir "2 семестр"\"Алгебра и геометрия"
mkdir "2 семестр"\"Основы программирования"

cd "1 семестр"\"Алгебра и геометрия" 
echo Лекции: Погожев Сергей Владимирович> readme.txt
echo Практика: Балыкина Юлия Ефимовна >> readme.txt

cd ..\"Мат анализ"
echo Лекции: Платонов Алексей Викторович> readme.txt
echo Практика: Лепихин Тимур Андреевич >> readme.txt

cd ..\"Основы программирования"
echo Лекции и практика: Погожев Сергей Владимирович> readme.txt

cd ..\"АВС"
echo Лекции: Моисеев Игорь Анатольевич> readme.txt