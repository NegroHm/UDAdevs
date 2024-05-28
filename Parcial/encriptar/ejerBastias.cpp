#include <iostream>
#include <string>

const int ROWS = 2;
const int COLS = 20;

// Función para llenar la matriz con el mensaje cifrado
void fillMatrix(char matrix[ROWS][COLS], const std::string &message) {
    int index = 0;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = message[index++];
        }
    }
}

// Función para desplazar un carácter
char shiftCharacter(char c, int shift) {
    if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' + shift) % 26;
    } else if (c >= 'a' && c <= 'z') {
        return 'a' + (c - 'a' + shift) % 26;
    } else {
        return c;
    }
}

// Función para desencriptar el mensaje
std::string decryptMessage(char matrix[ROWS][COLS]) {
    std::string decryptedMessage;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int shift = (j % 2 == 0) ? 1 : 2;
            decryptedMessage += shiftCharacter(matrix[i][j], shift);
        }
    }
    return decryptedMessage;
}

int main() {
    char matrix[ROWS][COLS];
    std::string message;
    
    std::cout << "Ingrese el mensaje cifrado (40 caracteres): ";
    std::getline(std::cin, message);

    // if (message.length() != 40) {
    //     std::cerr << "El mensaje debe tener exactamente 40 caracteres." << std::endl;
    //     return 1;
    // }

    fillMatrix(matrix, message);
    std::string decryptedMessage = decryptMessage(matrix);

    std::cout << "Mensaje descifrado: " << decryptedMessage << std::endl;
}