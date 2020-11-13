struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct hash Hash;

// Hash* ha;s

Hash* createHash(int tableSize);

void deleteHash(Hash* ha);

int valueString(char *str);

int insertHashWOColision(Hash* ha, struct aluno* al);

int searchtHashWOColision(Hash* ha, int mat, struct aluno* al);

int searchHash_EnderAberto(Hash* ha, int mat, struct aluno* al);

