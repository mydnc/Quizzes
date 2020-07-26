CXX=g++
FLAGS= -g -Wall -pedantic -Wextra
all: compile

run:
	./quizzes

compile: src/main.o src/Solution.o src/Answer.o src/TextAnswer.o src/OneAnswerCorrect.o src/BooleanAnswer.o src/Question.o src/TextQuestion.o src/TrueFalseQuestion.o src/MultipleChoiceQuestion.o src/User.o src/QuizOMatic.o src/FileHandling.o src/MenuItems.o
	$(CXX) -o quizzes src/main.o src/Solution.o src/Answer.o src/TextAnswer.o src/OneAnswerCorrect.o src/BooleanAnswer.o src/Question.o src/TextQuestion.o src/TrueFalseQuestion.o src/MultipleChoiceQuestion.o src/User.o src/QuizOMatic.o src/FileHandling.o src/MenuItems.o

QuizOMatic.o: src/QuizOMatic.cpp src/QuizOMatic.h
	$(CXX) $(FLAGS) -c src/QuizOMatic.cpp

User.o: src/User.cpp src/User.h
	$(CXX) $(FLAGS) -c src/User.cpp

MenuItems.o: src/MenuItems.cpp src/MenuItems.h
	$(CXX) $(FLAGS) -c src/MenuItems.cpp

FileHandling.o: src/FileHandling.cpp src/FileHandling.h
	$(CXX) $(FLAGS) -c src/FileHandling.cpp

Solution.o: src/Solution.cpp src/Solution.h
	$(CXX) $(FLAGS) -c src/Solution.cpp

Question.o: src/Question.cpp src/Question.h
	$(CXX) $(FLAGS) -c Question.cpp

TextQuestion.o: src/TextQuestion.cpp src/TextQuestion.h
	$(CXX) $(FLAGS) -c src/TextQuestion.cpp

TrueFalseQuestion.o: src/TrueFalseQuestion.cpp src/TrueFalseQuestion.h
	$(CXX) $(FLAGS) -c src/TrueFalseQuestion.cpp

MultipleChoiceQuestion.o: src/MultipleChoiceQuestion.cpp src/MultipleChoiceQuestion.h
	$(CXX) $(FLAGS) -c src/MultipleChoiceQuestion.cpp

Answer.o: src/Answer.cpp src/Answer.h
	$(CXX) $(FLAGS) -c src/Answer.cpp

TextAnswer.o: src/TextAnswer.cpp src/TextAnswer.h
	$(CXX) $(FLAGS) -c src/TextAnswer.cpp

OneAnswerCorrect.o: src/OneAnswerCorrect.cpp src/OneAnswerCorrect.h
	$(CXX) $(FLAGS) -c src/OneAnswerCorrect.cpp

BooleanAnswer.o: src/BooleanAnswer.cpp src/BooleanAnswer.h
	$(CXX) $(FLAGS) -c src/BooleanAnswer.cpp

main.o: src/main.cpp
	$(CXX) $(FLAGS) -c src/main.cpp

clean:
	rm -f src/*.o && rm -f quizzes
