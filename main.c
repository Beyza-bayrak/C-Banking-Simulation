

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct users {
    char name[50][50];
    char accountnumber[50][30];
    char password[50][20];
    int accbalance[50];
};

struct banknotes {
    int bank50;
    int bank100;
    int bank200;
};

void Winfile(struct users user, struct banknotes b, int k) {
    FILE *fp = fopen("musteri.txt", "w");
    if (fp) {
        for (int i = 0; i < k; i++) {
            fprintf(fp, "%s;%s;%s;%d\n", user.name[i], user.accountnumber[i], user.password[i], user.accbalance[i]);
        }
        fclose(fp);
    }

    FILE *fp2 = fopen("kasa.txt", "w");
    if (fp2) {
        fprintf(fp2, "%d;%d;%d\n", b.bank50, b.bank100, b.bank200);
        fclose(fp2);
    }
}

int main() {
    struct users user;
    FILE *fp;
    char satir[256];
    char *arr[4];
    int k = 0;

    fp = fopen("musteri.txt", "r");
    if (fp == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }

    while (fgets(satir, sizeof(satir), fp)) {
        int i = 0;
        char *parca = strtok(satir, ";");
        while (parca != NULL && i < 4) {
            arr[i] = parca;
            parca = strtok(NULL, ";");
            i++;
        }
        strcpy(user.name[k], arr[0]);
        strcpy(user.accountnumber[k], arr[1]);
        strcpy(user.password[k], arr[2]);
        user.accbalance[k] = atoi(arr[3]);
        k++;
    }

    fclose(fp);

    FILE *fp2;
    char line[256];
    char *arr2[3];
    struct banknotes b;
    int l = 0;

    fp2 = fopen("kasa.txt", "r");
    if (fp2 == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp2)) {
        int i = 0;
        char *parts = strtok(line, ";");
        while (parts != NULL && i < 3) {
            arr2[i] = parts;
            parts = strtok(NULL, ";");
            i++;
        }
        b.bank50= atoi(arr2[0]);
        b.bank100= atoi(arr2[1]);
        b.bank200= atoi(arr2[2]);
        l++;
    }

    fclose(fp2);
    char input_acc[6];
    char input_pass[20];
    //char name[20];
    int balance;
    int idx=-1;
     printf("Welcome to the online ATM system. Please first enter your account number, followed by your password.\n");

    printf("Account number: ");
    scanf("%s",input_acc);
    printf("password: ");
    scanf("%s",input_pass);

    for (int i = 0; i < k; i++) {
        if (strcmp(user.accountnumber[i], input_acc) == 0 &&
            strcmp(user.password[i],      input_pass) == 0)
        {
            idx = i;
            break;
        }
    }
    if (idx < 0) {
        printf("Hesap numarası veya şifre hatalı!\n");
        return 1;
    }

    // --- İlk girişse (default şifreyle) şifre değiştir ---
    if (strcmp(user.password[idx], "abc123") == 0) {
        printf("Bu ilk girişiniz, lütfen yeni şifrenizi girin: ");
        scanf("%19s", user.password[idx]);
        Winfile(user, b, k);
    }




while(1){
  printf("\nDear %s, your Account Balance is %d TL.\n"
           "You can now choose from the following banking operations:\n"
           "1. Deposit Funds\n"
           "2. Withdraw Funds\n"
           "3. Transfer Funds to Another Account\n"
           "4. Change Password\n"
            "0. Exit\n"
           "Your choice: ",
           user.name[idx], user.accbalance[idx]);
           printf("\n");

    int choice;
    scanf("%d", &choice);

   if (choice == 0) {
        printf("Thank you for using our ATM. Goodbye!\n");
        break;
    }
    //Deposit
  if(choice==1)
  {
    int b50;
      int b100;
      int b200;
    printf("Deposit Funds:\n\n");
    printf("200 TL banknotes count: ");
    scanf("%d", &b200);
    printf("100 TL banknotes count: ");
    scanf("%d", &b100);
    printf("50 TL banknotes count: ");
    scanf("%d", &b50);

      int toplam = 50 * b50 + 100 * b100 + 200 * b200;
       printf("\nPress Enter to deposit a total of %d TL into your account,\n", toplam);
    printf("or press Esc to exit without processing.\n");
     int ch = getch();
    if (ch == 13) {  // Enter key
        user.accbalance[idx] += toplam;
        // Update ATM cash register
        b.bank200   += b200;
        b.bank100   += b100;
        b.bank50    += b50;
    printf("\n\n%d TL has been deposited into your account.\n", toplam);
     Winfile(user, b, k);

    }
    else if (ch == 27) {  // Esc key
        printf("\n\nDeposit canceled. No changes have been made.\n");
    }
    else {
        printf("\n\nNo action taken. Returning to main menu.\n");
    }

    printf("\nPress any key to return to the main menu...");
   //kullanıcı bir tuşa basana kadar beklemeyi sağlar kapanmayı önler .
    getch;
   //burası tamam
  }
  if(choice==2) //withdrawn
  {
      int bForWithdraw;
      int count50;
      int count100;
      int count200;
      printf("Enter the amount to be withdrawn: ");
      scanf("%d", &bForWithdraw);
    if(user.accbalance[idx]>=50&&bForWithdraw%50==0)
    {
        if(bForWithdraw>user.accbalance[idx])
        {
            int b200=0;
            int b100=0;
            int b50=0;

            printf("The available amount is %d",user.accbalance[idx]);
            printf("Press Enter to proceed, or Esc to exit.");
            int balance2=user.accbalance[idx];

            int ch=getch();
            if(ch==13)
            {
              user.accbalance[idx]=0;
              printf("withdrawn is succesful.");
              while (balance2 >= 200)
                {
                    balance2 -= 200;
                    b200++;
                }
                while (balance2 >= 100)
                {
                    balance2 -= 100;
                    b100++;
                }
                while (balance2 >= 50)
                {
                    balance2 -= 50;
                    b50++;
                }
                b.bank50  -= b50;
                b.bank100 -= b100;
                b.bank200 -= b200;
             user.accbalance[idx]=0;
              Winfile(user, b, k);
             printf("You have received %d x 200 TL , %d x 100 TL and %d x 50TL  banknotes.",b200,b100,b50);

            }
            if(ch==27)
            {
               printf("\n\nWithdrawn canceled. No changes have been made.");

            }

        }
        else //kullanıcının girdiği değer bankadaki paradan büyük ise
        {
            int b200=0;
            int b100=0;
            int b50=0;

          printf("The available amount is %d",bForWithdraw);
          printf("Press Enter to proceed, or Esc to exit.");
          int balance2=bForWithdraw;
            int ch=getch();
            if(ch==13)
            {

              printf("withdrawn is succesful.");
             while (balance2 >= 200)
                {
                    balance2 -= 200;
                    b200++;
                }
                while (balance2 >= 100)
                {
                    balance2 -= 100;
                    b100++;
                }
                while (balance2 >= 50)
                {
                    balance2 -= 50;
                    b50++;
                }
                b.bank50  -= b50;
                b.bank100 -= b100;
                b.bank200 -= b200;
                user.accbalance[idx]=user.accbalance[idx]-balance2;
                 Winfile(user, b, k);
                 printf("You have received %d x 200 TL , %d x 100 TL and %d x 50TL  banknotes.",b200,b100,b50);

            }
            if(ch==27)
            {
               printf("\n\nWithdrawn canceled. No changes have been made.");
            }
        }


    }
    else //hesabında en az 50 varsa ve 50 nin katı değilse çekilemez.
    {
        printf("this process is not allowed.");
    }
    printf("press any key return to main  menu");
    getch();
  }

  if (choice == 3) {
    int moneyForTransfer = 0;
    int indexForTransfer = -1;
    char accountnum[6];

    printf("Transfer Funds to Another Account\n");
    printf("Recipient Account Number: ");
    scanf("%5s", accountnum);

    printf("Amount: ");
    scanf("%d", &moneyForTransfer);

    // Gönderenin bakiyesi yeterli mi?
    if (user.accbalance[idx] >= moneyForTransfer) {
        // Alıcı hesabı ara
        for (int i = 0; i < k; i++) {
            if (strcmp(user.accountnumber[i], accountnum) == 0) {
                indexForTransfer = i;
                break;
            }
        }

        if (indexForTransfer < 0)
            {
            // Hesap bulunamadı
            printf("Account not found.");
           } else {
            // Transferi gerçekleştir
            user.accbalance[idx] -= moneyForTransfer;
            user.accbalance[indexForTransfer] += moneyForTransfer;

            printf("Transfer successful.");
            Winfile(user,b,k);
        }
    }
    else {

        printf("Insufficient balance.");

    }
    printf("press any key return to main menu.");
    getch();
  }

  if (choice == 4)
  {
      char current_pass[20];
      char new_pass[20];
      char confirm_pass[20];

      printf("Change Password\n");

      int success = 0;

      for (int i = 0; i < 2; i++) {
          printf("Enter your current password: ");
          scanf("%s", current_pass);

          if (strcmp(user.password[idx], current_pass) == 0) {
              // Şifre doğruysa yeni şifre alma
              printf("Enter your new password: ");
              scanf("%s", new_pass);

              printf("Confirm your new password: ");
              scanf("%s", confirm_pass);

              if (strcmp(new_pass, confirm_pass) == 0) {
                  strcpy(user.password[idx], new_pass);  // Yeni şifreyi ata
                  printf("Password changed successfully.\n");
                  Winfile(user,b,k);
                  success = 1;
                  break;
              } else {
                  printf("Passwords do not match.\n");
              }
          } else {
              printf("Incorrect current password.\n");
          }
      }

      if (!success)
      {
          printf("Password change unsuccessful.\n");

      }
      printf("press any key return to main  menu");
      getch();

  }
  if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=0)
  {
    printf("invalid number.Please enter number.");
    printf("press any key return to main  menu");
    getch();

  }


}
    return 0;

}
