typedef struct veiculo Veiculo;

Veiculo* criarVeiculo(const char* placa, const char* marca, int ano);
char *getPlaca(Veiculo *veiculo);
char *getMarca(Veiculo *veiculo);
int getAno(Veiculo *veiculo);
