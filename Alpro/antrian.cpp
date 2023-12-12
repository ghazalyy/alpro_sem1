#include <iostream>
#include <cstdlib> 
#include <queue>

using namespace std;

#define max 5

string data[max];
int front = 0; // Front of the queue
int rear = 0;  // Rear of the queue

bool isFull()
{
    return rear == max;
}

bool isEmpty()
{
    return front == rear;
}

void view()
{
    if (!isEmpty())
    {
        cout << "Data antrian: " << endl;
        for (int i = front; i < rear; i++)
        {
            cout << i + 1 << ". " << data[i] << endl;
        }
    }
    else
    {
        cout << "Data antrian kosong" << endl;
    }

    if (isFull())
    {
        cout << "Data antrian penuh" << endl;
    }

    cout << endl;
}

void enqueue()
{
    if (!isFull())
    {
        cout << "Masukkan data: ";
        cin >> data[rear];
        rear++;
    }
    else
    {
        cout << "Data antrian penuh, tidak bisa menambahkan lagi." << endl;
    }
}

void dequeue()
{
    if (!isEmpty())
    {
        cout << "Dequeue Operation: " << data[front] << " keluar dari antrian." << endl;
        for (int i = front; i < rear - 1; i++)
        {
            data[i] = data[i + 1];
        }
        rear--;
    }
    else
    {
        cout << "Data antrian kosong, tidak ada yang bisa dihapus." << endl;
    }
}

int main()
{
    int menu;

x:
    system("cls");
    view();
    cout << "1. Menu Enqueue" << endl;
    cout << "2. Menu Dequeue" << endl;
    cout << "Silahkan masukkan menu: ";
    cin >> menu;

    switch (menu)
    {
    case 1:
        system("cls");
        enqueue();
        break;
    case 2:
        system("cls");
        dequeue();
        break;
    default:
        cout << "Menu tidak valid." << endl;
        break;
    }

    goto x;

    return 0;
}
