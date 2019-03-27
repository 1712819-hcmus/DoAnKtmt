#include "Function.h"
#include <fstream>
#include <vector>
#include <limits>

int main(int argc, char **argv)
{
	/*argc = 3;
	argv[1] = "Input_QFloat.txt";
	argv[2] = "Output_QFloat.txt";*/
	if (argc != 3)
	{
		cout << "\nHuong dan su dung!";
		cout << "\nVui long nhap du so luong file.";
		return 0;
	}

	QInt I, E, V;

	
	//File input************************************************************
	ifstream FileIn;
	FileIn.open(argv[1], ios_base::in);
	if (!FileIn)
	{
		cout << "\nKhong ton tai file. Vui long kiem tra lai!";
		return 0;
	}

	vector<string> KQ; //vector save result;
	
	string type; //Phan biet loai phai input
	type = argv[1];
	size_t temp1 = type.find("QInt");
	type = argv[2];
	size_t temp2 = type.find("QFloat");
	if (temp1 != -1) {
		while (!FileIn.eof())
		{
			int q; //Luu co s?
			FileIn >> q;
			FileIn.seekg(1, 1);

			//H? 2 =====================================================================
			if (q == 2)
			{
				string s1, s2;
				FileIn >> s1 >> s2;

				if (s1 == "10")
				{
					//d?i s2 sang h? 10
					s2.insert(0, "b"); //Thêm b vào v? trí 0.
					I = s2;
					KQ.push_back(I.PrinQInt(10));
				}
				else if (s1 == "16")
				{
					//d?i s2 sang h? 16
					s2.insert(0, "b"); //Thêm b vào v? trí 0.
					I = s2;
					KQ.push_back(I.PrinQInt(16));
				}
				//N?U KHÔNG PH?I Ð?I MÀ LÀ TÍNH TOÁN:
				if (s2 == "+" || s2 == "-" || s2 == "*" || s2 == "/")
				{
					string s3;
					FileIn >> s3;
					if (s2 == "+")
					{
						s1.insert(0, "b");
						s3.insert(0, "b");
						I = s1;
						E = s3;
						V = I + E;
						KQ.push_back(V.PrinQInt(2));
					}
					else if (s2 == "-")
					{
						s1.insert(0, "b");
						s3.insert(0, "b");
						I = s1;
						E = s3;
						V = I - E;
						KQ.push_back(V.PrinQInt(2));
					}
					else if (s2 == "*")
					{
						s1.insert(0, "b");
						s3.insert(0, "b");
						I = s1;
						E = s3;
						V = I * E;
						KQ.push_back(V.PrinQInt(2));
					}
					else if (s2 == "/")
					{
						s1.insert(0, "b");
						s3.insert(0, "b");
						I = s1;
						E = s3;
						V = I / E;
						KQ.push_back(V.PrinQInt(2));
					}
				}
			}
			//H? 10 =====================================================================
			else if (q == 10)
			{
				string s1, s2;
				FileIn >> s1 >> s2;
				if (s1 == "2")
				{
					//H? 10-> h? 2
					I = s2;
					KQ.push_back(I.PrinQInt(2));
				}
				else if (s1 == "16")
				{
					//H? 10-> h? 16
					I = s2;
					KQ.push_back(I.PrinQInt(16));
				}
				//N?U KHÔNG PH?I Ð?I MÀ LÀ TÍNH TOÁN:
				if (s2 == "+" || s2 == "-" || s2 == "*" || s2 == "/")
				{
					string s3;
					FileIn >> s3;
					if (s2 == "+")
					{
						I = s1;
						E = s3;
						V = I + E;
						KQ.push_back(V.PrinQInt(10));
					}
					else if (s2 == "-")
					{
						I = s1;
						E = s3;
						V = I - E;
						KQ.push_back(V.PrinQInt(10));
					}
					else if (s2 == "*")
					{
						I = s1;
						E = s3;
						V = I * E;
						KQ.push_back(V.PrinQInt(10));
					}
					else if (s2 == "/")
					{
						I = s1;
						E = s3;
						V = I / E;
						KQ.push_back(V.PrinQInt(10));
					}
				}
				//10 5678 >> 2
				else if (s2 == ">>")
				{
					int x; //S? l?n d?ch sang ph?i
					FileIn >> x;
					I = s1;
					E = I >> x;
					KQ.push_back(E.PrinQInt(10));
				}
				else if (s2 == "<<")
				{
					int x; //S? l?n d?ch sang trái
					FileIn >> x;
					I = s1;
					E = I << x;
					KQ.push_back(E.PrinQInt(10));
				}
			}
			//H? 16 =====================================================================
			else if (q == 16)
			{
				string s1, s2;
				FileIn >> s1 >> s2;

				if (s1 == "2")
				{
					//d?i s2 sang h? 10
					s2.insert(0, "0x"); //Thêm "0x" vào v? trí 0.
					I = s2;
					KQ.push_back(I.PrinQInt(2));
				}
				else if (s1 == "10")
				{
					//d?i s2 sang h? 16
					s2.insert(0, "0x"); //Thêm "0x" vào v? trí 0.
					I = s2;
					KQ.push_back(I.PrinQInt(10));
				}
				//N?U KHÔNG PH?I Ð?I MÀ LÀ TÍNH TOÁN:
				if (s2 == "+" || s2 == "-" || s2 == "*" || s2 == "/")
				{
					string s3;
					FileIn >> s3;
					if (s2 == "+")
					{
						s1.insert(0, "0x");
						s3.insert(0, "0x");
						I = s1;
						E = s3;
						V = I + E;
						KQ.push_back(V.PrinQInt(16));
					}
					else if (s2 == "-")
					{
						s1.insert(0, "0x");
						s3.insert(0, "0x");
						I = s1;
						E = s3;
						V = I - E;
						KQ.push_back(V.PrinQInt(16));
					}
					else if (s2 == "*")
					{
						s1.insert(0, "0x");
						s3.insert(0, "0x");
						I = s1;
						E = s3;
						V = I * E;
						KQ.push_back(V.PrinQInt(16));
					}
					else if (s2 == "/")
					{
						s1.insert(0, "0x");
						s3.insert(0, "0x");
						I = s1;
						E = s3;
						V = I / E;
						KQ.push_back(V.PrinQInt(16));
					}
				}
			}
		}
		FileIn.close();
		//File output*******************************************************************
		ofstream FileOut;
		FileOut.open(argv[2], ios_base::out);

		int size = KQ.size(); //Number of saved results
		for (int i = 0; i < size; i++)
		{
			FileOut << KQ[i] << endl;
		}

		FileOut.close();
	}
	else if (temp2 != -1) {
		while (!FileIn.eof())
		{
			int q; //Luu co s?
			FileIn >> q;
			FileIn.seekg(1, 1);

			if (q ==2) {
				string s1, s2;
				FileIn >> s1 >> s2;
				QFloat a;
				a.ScanQFloat(s2, 2);
				KQ.push_back(a.PrintQFloat(10));
			}
			if (q == 10) {
				string s1, s2;
				FileIn >> s1 >> s2;
				QFloat a;
				a.ScanQFloat(s2, 10);
				KQ.push_back(a.PrintQFloat(2));
			}
		}
		FileIn.close();

		//File output*******************************************************************
		ofstream FileOut;
		FileOut.open(argv[2], ios_base::out);

		int size = KQ.size(); //Number of saved results
		for (int i = 0; i < size; i++)
		{
			FileOut << KQ[i] << endl;
		}

		FileOut.close();

	}
	cin.ignore();
	cout << "\nDa thuc hien xong. Vui long kiem tra ket qua file " << argv[2] << endl;
	return 0;
}

