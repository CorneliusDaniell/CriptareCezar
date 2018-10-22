#include<stdio.h>
#include<stdlib.h>

void CezarCrypt(char message[], int key);
void CezarDecrypt(char message[], int key);


int main()
{
	char message[50];
	int i, key,x;

	printf("Message to encrypt: ");
	gets(message);
	printf("Key: ");
	scanf("%d", &key);

	printf("1 = Encrypt the message.\n");
	printf("2 = Decrypt the message.\n");
	scanf("%d", &x);

	switch (x)
	{
	case 1:
		CezarCrypt(message, key);
		break;

	case 2:
		CezarDecrypt(message, key);
		break;

	default:
		printf("\n Choise 1 or 2 !! \n");
	}


	getch();
	return 0;
}

void CezarCrypt(char message[], int key) {
	char messageEncrypted;
	int i;
	for (i = 0; message[i] != '\0'; ++i) {
		messageEncrypted = message[i];

		if (messageEncrypted >= 'a' && messageEncrypted <= 'z') {
			messageEncrypted = messageEncrypted + key;

			if (messageEncrypted > 'z') {
				messageEncrypted = messageEncrypted - 'z' + 'a' - 1;
			}

			message[i] = messageEncrypted;
		}
		else if (messageEncrypted >= 'A' && messageEncrypted <= 'Z') {
			messageEncrypted = messageEncrypted + key;

			if (messageEncrypted > 'Z') {
				messageEncrypted = messageEncrypted - 'Z' + 'A' - 1;
			}

			message[i] = messageEncrypted;
		}
	}
	printf("Encrypted message: %s", message);
}

void CezarDecrypt(char message[], int key) {
	char messageDecrypted;
	int i;
	for (i = 0; message[i] != '\0'; ++i) {
		messageDecrypted = message[i];

		if (messageDecrypted >= 'a' && messageDecrypted <= 'z') {
			messageDecrypted = messageDecrypted - key;

			if (messageDecrypted < 'a') {
				messageDecrypted = messageDecrypted + 'z' - 'a' + 1;
			}

			message[i] = messageDecrypted;
		}
		else if (messageDecrypted >= 'A' && messageDecrypted <= 'Z') {
			messageDecrypted = messageDecrypted - key;

			if (messageDecrypted < 'A') {
				messageDecrypted = messageDecrypted + 'Z' - 'A' + 1;
			}

			message[i] = messageDecrypted;
		}
	}

	printf("\n Decrypted message: %s", message);
}