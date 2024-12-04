# Определяем переменные
CXX = g++
CXXFLAGS = -std=c++11 -Wall -O0 -g
LDFLAGS = -lcryptopp
SRC = hash.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = hash

# Правило по умолчанию
all: $(TARGET)

# Правило для создания исполняемого файла
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

# Правило для компиляции исходных файлов в объектные
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка сгенерированных файлов
clean:
	rm -f $(OBJ) $(TARGET)

# Правило для вывода информации о использовании
help:
	@echo "Makefile для сборки программы хэширования с использованием Crypto++"
	@echo "Команды:"
	@echo "  make        - Сборка программы"
	@echo "  make clean  - Удаление объектных файлов и исполняемого файла"
	@echo "  make help   - Показать это сообщение"
