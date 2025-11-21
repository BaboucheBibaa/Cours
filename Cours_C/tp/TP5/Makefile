# Nom de l’exécutable
EXEC = prog

# Compilateur
CC = gcc

# Options de compilation
CFLAGS = -Wall -Wextra -g

# Fichiers sources et objets
SRC = main_liste.c liste.c
OBJ = $(SRC:.c=.o)

# Règle par défaut
all: $(EXEC)

# Règle de création de l’exécutable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Règle générique pour compiler un .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l’exécutable
clean:
	rm -f $(OBJ) $(EXEC)
