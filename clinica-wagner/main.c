#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

int data_hora_atual() {
  
  time_t segundos;
 
  struct tm *data_hora_atual;

  time(&segundos);

  data_hora_atual = localtime(&segundos);

  printf("\tData atual: %d/%d/%d\n", data_hora_atual->tm_mday,
         data_hora_atual->tm_mon + 1, data_hora_atual->tm_year + 1900);
  printf("\tHora atual: %d:%d:%d\n", data_hora_atual->tm_hour - 3,
         data_hora_atual->tm_min, data_hora_atual->tm_sec);

  return 0;
}
int barra_carregando() {
  char barra[11] = "----------";      
  printf("Clínica Wagner: %s", barra);   
  fflush(stdout);                     
  for (int i = 0; i < 10; i++) {       
    sleep(1);                         
    printf("\b-");                    
    fflush(stdout);                   
    barra[i] = '*';                   
    printf("\rClínica Wagner: %s", barra); 
    fflush(stdout);                  
  }
  system("clear");
  return 0;
}
int capa(){
   printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t+----------------------------------------"
         "------------------------+\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                                        "
         "                        |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                 =>SEJA BEM-VINDO<=     "
         "                        |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                   Clínica Wagner       "
         "                        |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                                        "
         "                        |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\tRua: Avenida Elis Regina \t\tN: 379     "
         "                  |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                                        "
         "                        |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\tBairro: Santa Rosa  "
         "\t\t\tCidade: Uberlandia [MG]      |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                                        "
         "                        |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\tTelefone: (34)3293-3211               "
         "                       |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                                        "
         "                        |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\tE-mail: wagner321@gmail.com.br        "
         "                       |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t|                                        "
         "                        |\n");
  printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t+----------------------------------------"
         "------------------------+\n\n");
}
int is_valid_phone(const char *phone){
  int len = strlen(phone);
  if (len != 11 ){
    return 0;
  }
  for(int i =0;i<len;i++){
    if(!isdigit(phone[i])){
      return 0;
    }
  }
  return 1;
}
int is_valid_email(const char *email ){
  return strchr(email, '@') != NULL;
}
int cw(){
printf("  ######     ##        ##\n");
printf("##     ##    ##   ##   ##\n");
printf("##           ##   ##   ##\n");
printf("##           ##   ##   ##\n");
printf("##     ##    ##   ##   ##\n");
printf("  ######       ###  ###\n\n");
}
int capadois(){
  printf("\n\tCom anos de experiência e comprometimento com o bem-estar dos pacientes, oferecemos atendimento personalizado e soluções médicas de qualidade.\n\t\t\t\tAgende sua consulta hoje mesmo e comece sua jornada em direção a uma vida mais saudável e feliz\n\n.");
  return 0;
}
int main() {

  FILE *fptr;
  char nome[500];
  int opcao;
  char medico[500];
  char opcaon[200];
  char cpf[12];
  char idade[50];
  char telefone[50];
  char E_mail[50];
  char nascimentos[50];
  char nome_pai[50];
  char nome_mae[50];
  int ok;
  char dia[500];   
  int maxTentativas = 3;
  int tentativas = 0;
  
  fptr = fopen("consultas.txt", "a");

  system("clear");

  
  
  capa();

  capadois();
  
  barra_carregando();

  data_hora_atual();  

  // cadastrar
  printf("\nDigite seu nome: ");
  fgets(nome, sizeof(nome), stdin);
  printf("Nome da mãe: ");
  fgets(nome_mae, sizeof(nome_mae), stdin);
  printf("Nome do pai: ");
  fgets(nome_pai, sizeof(nome_pai), stdin);
  printf("Digite seu CPF (11 dígitos): ");
  while (1) {
    scanf("%s", cpf);

    if (strlen(cpf) != 11) {
        printf("\nCPF inválido. Deve conter 11 dígitos.\nTente novamente: ");
        continue; 
    }
    int valid = 1;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            valid = 0;
            break;
        }
    }

    if (!valid) {
        printf("\nCPF inválido. Deve conter apenas dígitos.\nTente novamente: ");
        continue;
    }

    break; 
      }
  printf("Telefone(11 dígitos): ");
  while(1){
    scanf("%s", telefone);
    if(!is_valid_phone(telefone)){
      printf("\nTelefone inválido.Deve 11 dígitos.\nTente novamente: ");
        continue;
    }
    break;
  }
  printf("E-mail: ");
  while(1){
    scanf("%s", E_mail);
    if(!is_valid_email(E_mail)){
      printf("\nE-mail inválido.Deve conte '@'.\nTente novamente: ");
        continue;
    }
    break;
  }
  printf("Data de nascimento (dd/mm/aaaa): ");
    while (1) {
        scanf("%s", nascimentos);

        if (strlen(nascimentos) != 10 || nascimentos[2] != '/' || nascimentos[5] != '/') {
            printf("\nFormato inválido. Use dd/mm/aaaa.\nTente novamente: ");
            continue;
        }

        int day, month, year;
        if (sscanf(nascimentos, "%d/%d/%d", &day, &month, &year) != 3) {
            printf("\nData inválida.\nTente novamente: ");
            continue;
        }

        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2100) {
            printf("\nData fora do intervalo válido.\nTente novamente: ");
            continue;
        }
        break;
    }

  system("clear");

  cw();

  printf("\t\t+---------------------------------------+\n");
  printf("\t\t|\tQuer marcar qual tipo de consulta?  |\n");
  printf("\t\t|                                       |\n");
  printf("\t\t|\t\t1-Clinico geral                 |\n");
  printf("\t\t|                                       |\n");
  printf("\t\t|\t\t2-Psiquiatra                    |\n");
  printf("\t\t|                                       |\n");
  printf("\t\t|\t\t3-Otorrinolaringologista        |\n");
  printf("\t\t|                                       |\n");
  printf("\t\t|\t\t4-Cardiologista                 |\n");
  printf("\t\t|                                       |\n");  
  printf("\t\t|\t\t5-Neurologista                  |\n");
  printf("\t\t|                                       |\n");  
  printf("\t\t|\t\t6-Ortopedista                   |\n");
  printf("\t\t|                                       |\n");
  printf("\t\t|\t\t7-Exame                         |\n");
  printf("\t\t|                                       |\n");
  printf("\t\t|\t\t0-Encerrar o programa           |\n");
  printf("\t\t|                                       |\n");
  printf("\t\t+---------------------------------------+");
  printf("\n\n");
    printf("\nDigite a opcao desejada: ");
  scanf("%d", &opcao);

  system("clear");
  
  switch (opcao) {
  case 0:
    return 0;
  case 1:
    cw();
    printf("\n\t\t=>Clinicos gerais disponíveis:\n\n");
    strcpy(opcaon, "Clinico Geral");

    printf("\t+-----------------------------------------------------------+\n");
    printf("\t|                                                           |\n");
    printf("\t| Dr Paulo Souza | 9:00 até 17:30 | segunda, quarta e sexta |\n");
    printf("\t|                                                           |\n");
    printf("\t| Dra Maria Julia | 8:00 até 17:00 | terça e quinta         |\n");
    printf("\t|                                                           |\n");
    printf("\t| Dr Miguel | 10:00 até 17:30 | segunda até sabado          |\n");
    printf("\t|                                                           |\n");
    printf("\t+-----------------------------------------------------------+\n\n");
    getchar();

    data_hora_atual(); 

    printf("\n");

    while (tentativas < maxTentativas) {
        printf("Médico(a): ");
        fgets(medico, sizeof(medico), stdin);
        medico[strcspn(medico, "\n")] = '\0';

        // Verifique se o médico digitado existe
        if (strcmp(medico, "Paulo Souza") == 0 ||
            strcmp(medico, "Paulo") == 0 ||
            strcmp(medico, "Maria Julia") == 0 ||
            strcmp(medico, "Maria") == 0 ||
            strcmp(medico, "Miguel") == 0) {
            printf("Médico encontrado: %s\n", medico);
            break; // Saia do loop se o médico for válido
        } else {
            printf("Médico não encontrado. Tente novamente.\n");
            tentativas++;
        }
    }

    if (tentativas == maxTentativas) {
        printf("Número máximo de tentativas atingido. Encerrando o programa.\n");
        return 0;
    }
    printf("Dia da semana: ");
    scanf("%s", dia);
    getchar();
    
    break;

  case 2:
    cw();
    printf("\t\t=>Psiquiatras disponíveis:\n\n");
    strcpy(opcaon, "Psiquiatra");

    printf("\t+---------------------------------------------------------------+\n");
    printf("\t|                                                               |\n");
    printf("\t| Dra Helena Martins | 9:00 até 17:30 | segunda, quarta e sexta |\n");
    printf("\t|                                                               |\n");
    printf("\t| Dr Davi Fernandes | 7:30 até 17:00 | terça e quinta           |\n");
    printf("\t|                                                               |\n");
    printf("\t| Dra Laura Barbosa | 10:00 até 17:30 | segunda até sabado      |\n");
    printf("\t|                                                               |\n");
    printf("\t+---------------------------------------------------------------+\n\n");
    getchar();

    data_hora_atual(); 

    printf("\n");
    
    while (tentativas < maxTentativas) {
        printf("Médico(a): ");
        fgets(medico, sizeof(medico), stdin);
        medico[strcspn(medico, "\n")] = '\0';

       
        if (strcmp(medico, "Helena Martins") == 0 ||
            strcmp(medico, "Helena") == 0 ||
            strcmp(medico, "Davi Fernandes") == 0 ||
            strcmp(medico, "Davi") == 0 ||
            strcmp(medico, "Laura") == 0 ||
            strcmp(medico, "Dra Laura Barbosa") == 0) {
            printf("Médico encontrado: %s\n", medico);
            break; 
        } else {
            printf("Médico não encontrado. Tente novamente.\n");
            tentativas++;
        }
    }

    if (tentativas == maxTentativas) {
        printf("Número máximo de tentativas atingido. Encerrando o programa.\n");
        return 0;
    }
    printf("Dia da semana: ");
    scanf("%s", dia);
    getchar();
    
    break;

  case 3:
    cw();
    printf("\n\t\t=>Otorrinolaringologistas disponíveis:\n\n");
    strcpy(opcaon, "Otorrinolaringologista");

    printf("\t+------------------------------------------------------------+\n");
    printf("\t|                                                            |\n");
    printf("\t| Dr Samuel Gomes | 8:00 até 17:30 | segunda, quarta e sexta |\n");
    printf("\t|                                                            |\n");
    printf("\t| Dra Alice Costa | 7:30 até 17:00 | terça e quinta          |\n");
    printf("\t|                                                            |\n");
    printf("\t| Dra Helena Ribeira | 10:00 até 17:30 | segunda até sabado  |\n");
    printf("\t|                                                            |\n");
    printf("\t+------------------------------------------------------------+\n\n");
    getchar();

    data_hora_atual(); 

    printf("\n");
    
     while (tentativas < maxTentativas) {
        printf("Médico(a): ");
        fgets(medico, sizeof(medico), stdin);
        medico[strcspn(medico, "\n")] = '\0';

       
        if (strcmp(medico, "Samuel Gomes") == 0 ||
            strcmp(medico, "Samuel") == 0 ||
            strcmp(medico, "Alice Costa") == 0 ||
            strcmp(medico, "Alice") == 0 ||
            strcmp(medico, "Helena") == 0 ||
            strcmp(medico, "Helena Ribeira") == 0) {
            printf("Médico encontrado: %s\n", medico);
            break; 
        } else {
            printf("Médico não encontrado. Tente novamente.\n");
            tentativas++;
        }
    }

    if (tentativas == maxTentativas) {
        printf("Número máximo de tentativas atingido. Encerrando o programa.\n");
        return 0;
    }
    printf("Dia da semana: ");
    scanf("%s", dia);
    getchar();
    
    break;

  case 4:cw();
    printf("\n\t\t=>Cardiologistas disponíveis:\n\n");
    strcpy(opcaon, "Cardiologista");

    printf("\t+---------------------------------------------------------------+\n");
    printf("\t|                                                               |\n");
    printf("\t| Dra Sophia  Alves | 8:00 até 17:30 | segunda, quarta e sexta  |\n");
    printf("\t|                                                               |\n");
    printf("\t| Dra Isabella Ferreira | 7:30 até 17:00 | terça e quinta       |\n");
    printf("\t|                                                               |\n");
    printf("\t| Dr Lucas Rodrigues | 10:00 até 17:30 | segunda até sabado     |\n");
    printf("\t|                                                               |\n");
    printf("\t+---------------------------------------------------------------+\n\n");
    getchar();

    data_hora_atual(); 

    printf("\n");
    
    while (tentativas < maxTentativas) {
        printf("Médico(a): ");
        fgets(medico, sizeof(medico), stdin);
        medico[strcspn(medico, "\n")] = '\0';

       
        if (strcmp(medico, "Sophia  Alves") == 0 ||
            strcmp(medico, "Sophia") == 0 ||
            strcmp(medico, "Isabella Ferreira") == 0 ||
            strcmp(medico, "Isabella") == 0 ||
            strcmp(medico, "Lucas") == 0 ||
            strcmp(medico, "Lucas Rodrigues") == 0) {
            printf("Médico encontrado: %s\n", medico);
            break; 
        } else {
            printf("Médico não encontrado. Tente novamente.\n");
            tentativas++;
        }
    }

    if (tentativas == maxTentativas) {
        printf("Número máximo de tentativas atingido. Encerrando o programa.\n");
        return 0;
    }
    printf("Dia da semana: ");
    scanf("%s", dia);
    getchar();
    
    break;

  case 5:
    cw();
    printf("\n\t\t=>Neurologistas disponíveis:\n\n");
    strcpy(opcaon, "Neurologista");

    printf("\t+------------------------------------------------------------+\n");
    printf("\t|                                                            |\n");
    printf("\t| Dr Samuel Alves | 8:00 até 17:30 | segunda, quarta e sexta |\n");
    printf("\t|                                                            |\n");
    printf("\t| Dr Lorenzo Pereira | 7:30 até 17:00 | terça e quinta       |\n");
    printf("\t|                                                            |\n");
    printf("\t| Dr Felipe Lima | 10:00 até 17:30 | segunda até sabado      |\n");
    printf("\t|                                                            |\n");
    printf("\t+------------------------------------------------------------+\n\n");
    getchar();

    data_hora_atual(); 

    printf("\n");
    
    while (tentativas < maxTentativas) {
        printf("Médico(a): ");
        fgets(medico, sizeof(medico), stdin);
        medico[strcspn(medico, "\n")] = '\0';

       
        if (strcmp(medico, "Samuel Alves") == 0 ||
            strcmp(medico, "Samuel") == 0 ||
            strcmp(medico, "Lorenzo Pereira") == 0 ||
            strcmp(medico, "Lorenzo") == 0 ||
            strcmp(medico, "Felipe") == 0 ||
            strcmp(medico, "Felipe Lima") == 0) {
            printf("Médico encontrado: %s\n", medico);
            break; 
        } else {
            printf("Médico não encontrado. Tente novamente.\n");
            tentativas++;
        }
    }

    if (tentativas == maxTentativas) {
        printf("Número máximo de tentativas atingido. Encerrando o programa.\n");
        return 0;
    }
    printf("Dia da semana: ");
    scanf("%s", dia);
    getchar();
    
    break;

  case 6:
    cw();
    printf("\n\t\t=>Ortopedistas disponíveis:\n\n");
    strcpy(opcaon, "Ortopedista");

    printf("\t+----------------------------------------------------------------+\n");
    printf("\t|                                                                |\n");
    printf("\t| Dra Maria Valentina | 8:00 até 17:30 | segunda, quarta e sexta |\n");
    printf("\t|                                                                |\n");
    printf("\t| Dra Diana Santa | 7:30 até 17:00 | terça e quinta              |\n");
    printf("\t|                                                                |\n");
    printf("\t| Dra Joana Oliveira | 10:00 até 17:30 | segunda até sabado      |\n");
    printf("\t|                                                                |\n");
    printf("\t+----------------------------------------------------------------+\n\n");
    getchar();

    data_hora_atual();

    printf("\n");
    
       while (tentativas < maxTentativas) {
        printf("Médico(a): ");
        fgets(medico, sizeof(medico), stdin);
        medico[strcspn(medico, "\n")] = '\0';

      
        if (strcmp(medico, "Dra Maria Valentina") == 0 ||
            strcmp(medico, "Maria") == 0 ||
            strcmp(medico, "Diana") == 0 ||
            strcmp(medico, "Dra Diana Santa") == 0 ||
            strcmp(medico, "Joana") == 0 ||
            strcmp(medico, "Joana Oliveira") == 0) {
            printf("Médico encontrado: %s\n", medico);
            break; 
        } else {
            printf("Médico não encontrado. Tente novamente.\n");
            tentativas++;
        }
    }

    if (tentativas == maxTentativas) {
        printf("Número máximo de tentativas atingido. Encerrando o programa.\n");
        return 0;
    }
    printf("Dia da semana: ");
    scanf("%s", dia);
    getchar();
    
    break;

  case 7:
    cw();
    strcpy(opcaon, "Exame");
    printf("\n");
    printf("\t+-----------------------------------------------------------------+\n");
    printf("\t|                                                                 |\n");
    printf("\t|\t=>Exames são feitos de segunda a sábado das 7:30 até as 17:30 |\n");
    printf("\t|                                                                 |\n");
    printf("\t+-----------------------------------------------------------------+\n");
    printf("\n1-OK\n");
    scanf("%d", &ok);

    break;
    
  default:
    printf("OPÇÃO INVÁLIDA.\n");
    return 0;
  }

  if (opcao==7){
    fprintf(fptr,
          "\n\t\t\t\tCLINICA WAGNE\nRua: Avenida Elis Regina \tN: 379\nBairro: Santa Rosa  \tCidade: Uberlandia [MG]\n\nNome: %sCPF: %s\nTelefone: %s\nE-mail: %s\nData de nascimento: "
          "%s\nNome da mãe: %sNome do pai: %sOpção escolhida: %s\n",
          nome, cpf, telefone, E_mail, nascimentos, nome_mae,
          nome_pai, opcaon);
  fclose(fptr);
  } else { 
  fprintf(fptr,
          "\n\t\t\t\tCLINICA WAGNER\nRua: Avenida Elis Regina \tN: 379\nBairro: Santa Rosa  \tCidade: Uberlandia [MG]\n\nNome: %sCPF: %s\nTelefone: %s\nE-mail: %s\nData de nascimento: "
          "%s\nNome da mãe: %sNome do pai: %sOpção escolhida: %s\nDr (a): %s\nDia da semana: %s\n",
          nome, cpf, telefone, E_mail, nascimentos, nome_mae,
          nome_pai, opcaon, medico, dia);
  fclose(fptr);
  }
  
  system("clear");
  barra_carregando();
  system("clear");

  printf("\t\t+------------------------------------------------------------------------------------------------------+\n");
  printf("\t\t|                                                                                                      |\n");
  printf("\t\t|  \t\t=> Consulta marcada com sucesso!                                                               |\n");
  printf("\t\t|                                                                                                      |\n");
  printf("\t\t|                                                                                                      |\n");
  printf("\t\t|                                                                                                      |\n");
  printf("\t\t|                                                                                                      |\n");
  printf("\t\t|\t\tCaso queira remarcar ou cancelar sua consulta contate-nos pelo telefone: (34) 3293-3211        |\n");
  printf("\t\t|                                                                                                      |\n");
  printf("\t\t|\t\tNÓS ESTAMOS ESPERANDO VOCÊ!                                                                    |\n");
  printf("\t\t|                                                                                                      |\n");
  printf("\t\t+------------------------------------------------------------------------------------------------------+\n");
  
  
  return 0;
}