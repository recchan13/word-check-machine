#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string cetak(string input);
void selesai(string input);
void cekMasukan (string masukan);
void iniInt(string input, int i, int n);
void iniString(string input, int i, int n);

bool isAngka(char a);
void perkalian();
void pertambahan();
void pengurangan();
void pembagian();

bool done=false;

int main (){
	string input;
	
	while (!done){
		cout<<"# ";
		getline(cin,input);
		
		cout<<"> ";
		// hapus spasi (abaikan spasi diawal)
		int i=0; bool hapus=false;
		do{
			if(input[i]!=' '){
				break;
			}else{
				hapus=true;
				input.erase(0,1);
			}
			if(hapus){
				i=0;
			}else{
				i++;
			}
		}while(i<input.length());

		if (input[0]=='c' || input[0]=='C'){
			cout<<cetak(input)<<endl;
		}else if (input[0]=='s' || input[0]=='S'){
			selesai(input);
		}else{
			cout<<"Kode tidak sesuai dengan peraturan.";
		}	
	}
	cout<<"terimakasih telah menggunakan compiler ini";
	cout<<endl;
	return 0;
}

string cetak(string input){
	bool kebenaran=true;
	
	if (input[1]=='e' || input[1]=='E'){
	}else{
		kebenaran=false;
		return "Kode tidak sesuai dengan peraturan.";
	}
	
	if ((input[2]=='t'||input[2]=='T') && kebenaran){
	}else{
		kebenaran=false;
		return "Kode tidak sesuai dengan peraturan.";
	}
	
	if ((input[3]=='a'||input[3]=='A') && kebenaran){
	}else{
		kebenaran=false;
		return "Kode tidak sesuai dengan peraturan.";
	}
	
	string masukan;
	if ((input[4]=='k'||input[4]=='K') && kebenaran){
		// getline(cin,masukan);
	}else{
		kebenaran=false;
		return "Kode tidak sesuai dengan peraturan.";
	}
	
	cekMasukan(input);

	
	if (kebenaran){
		return ""; 
	}else{
		return "Kode tidak sesuai dengan peraturan.";
	}
}

void selesai(string input){
	bool kebenaran=true;
	
	if (input[1]=='e' || input[1]=='E'){
	}else{
		kebenaran=false;
	}
	
	if ((input[2]=='l'||input[2]=='L') && kebenaran){
	}else{
		kebenaran=false;
	}
	
	if ((input[3]=='e'||input[3]=='E') && kebenaran){
	}else{
		kebenaran=false;
	}
	
	if (input[4]=='s' || input[4]=='S'){
	}else{
		kebenaran=false;
	}
	
	if ((input[5]=='a'||input[5]=='A') && kebenaran){
	}else{
		kebenaran=false;
	}
	
	if ((input[6]=='i'||input[6]=='I') && kebenaran){
		// getline(cin,masukan);
	}else{
		kebenaran=false;
	}
	
	int i=7;
	bool titikKoma=false;
	while (i<input.length()){
		if (input[i]==';'){
			i++;
			titikKoma=true;
			kebenaran=true;
			break;
		}else if(input[i]==' '){
			kebenaran=true;
		}else{
			kebenaran=false;
			break;
		}i++;
	}
	if(!titikKoma){
		kebenaran=false;
	}
	if(kebenaran){
		while (i<input.length()){
			if(input[i]==' '){
				kebenaran=true;
			}else{
				kebenaran=false;
				break;
			}i++;
		}
	}
	done=kebenaran;
	if(!kebenaran){
		cout<<"Kode tidak sesuai dengan peraturan."<<endl;
	}
}

void cekMasukan (string input){
	int i=0;
	for (i=5;i<input.length();i++){
		if(input[i]!=' '){
			break;
		}
	}
	
	//mulai membaca inputan setelah spasi
	if(input[i]=='"'){
		i++;
		iniString(input,i,input.length());
	}else if (input[i]=='-' || input [i]=='0' || input [i]=='1' || input [i]=='2' || input [i]=='3' || input [i]=='4' || input [i]=='5' || input [i]=='6' || input [i]=='7' || input [i]=='8' || input [i]=='9'){
		//hapus semua selain operasi aritmatika		
		iniInt(input,i,input.length());
	}else{
		cout<<"Kode tidak sesuai dengan peraturan.";
	}
	
}

void iniString(string input, int i, int n){

	string huruf;
	int indeks=0;
	bool kebenaran=false;
	
	while (i<n){
		if(input[i]!='"'){
			// huruf[indeks]=input[i];  //masukkin ke huruf []
			huruf+=input[i];
			// indeks++;
		}else{
			i++;
			break;
		}
		i++;
	}
	
	while (i<n){
		if (input[i]==';'){
			i++;
			kebenaran=true;
			break;
		}else if(input[i]==' '){
			kebenaran=true;
		}else{
			kebenaran=false;
			break;
		}i++;
	}
	
	if(kebenaran){
		while (i<n){
			if(input[i]==' '){
				kebenaran=true;
			}else{
				kebenaran=false;
				break;
			}i++;
		}
	}
	
	if (kebenaran){
		cout<<huruf;
	}else{
		cout<<"Kode tidak sesuai dengan peraturan.";
	}
}

bool kali=true, bagi=true, tambah=true, kurang=true;
string inputAritmatika;
int sum=0;
int angkaA=0, angkaB=0;
int idxAwal=0, idxAkhir=0;
int beginAritmatika=0, finishAritmatika;
string tempA="", tempB="";

void iniInt(string input, int i, int n){
	kali=true; bagi=true; tambah=true; kurang=true;
	inputAritmatika="";
	sum=0;
	angkaA=0; angkaB=0;
	idxAwal=0; idxAkhir=0;
	beginAritmatika=0; finishAritmatika;
	tempA=""; tempB="";

	inputAritmatika=input;
	//hapus spasi
	int count=0;
	for(int j=0;j<inputAritmatika.length();j++){
		if(inputAritmatika[j]==' '){
			count++;
		}else{
			break;
		}
	}
	
	bool kebenaran=false;
	
	while (i<n){
		if(input[i]=='*' || input[i]=='/' || input[i]=='+' || input[i]=='-' || input [i]=='0' || input [i]=='1' || input [i]=='2' || input [i]=='3' || input [i]=='4' || input [i]=='5' || input [i]=='6' || input [i]=='7' || input [i]=='8' || input [i]=='9'){
			i++;
		}else{
			break;
		}
	}
	bool titikKoma=false;
	while (i<n){
		if (input[i]==';'){
			i++;
			titikKoma=true;
			kebenaran=true;
			break;
		}else if(input[i]==' '){
			kebenaran=true;
		}else{
			kebenaran=false;
			break;
		}i++;
	}
	
	if(kebenaran){
		while (i<n){
			if(input[i]==' '){
				kebenaran=true;
			}else{
				kebenaran=false;
				break;
			}i++;
		}
	}
	inputAritmatika.erase(0,count+1);

	//hapus cetak
	inputAritmatika.erase(0,5);
	
	while(kali){
        perkalian();
    }
    while(bagi){
        pembagian();
    }
    while(tambah){
        pertambahan();
    }
    while(kurang){
        pengurangan();
    }
	
	
	if (kebenaran && titikKoma){
		//cout inputan yang tlh benar
		for(i=0;i<inputAritmatika.length();i++){
			if(inputAritmatika[i]!=';'){
				cout<<inputAritmatika[i];
			}
		}
	}else{
		cout<<"Kode tidak sesuai dengan peraturan.";
	}
	
}

/**
 * 
 * function aritmatika
*/
bool isAngka(char a){
    if(a>='0' && a<='9'){
        return true;
    }
    return false;
}

void pengurangan(){
       sum=0;
           tempA=""; tempB="";
    int start=beginAritmatika;
    bool angkaMinus=false;
    if(inputAritmatika[beginAritmatika]=='-'){
        start++;
        angkaMinus=true;

    }
    int idx=0;
    for(int i=start;i<inputAritmatika.length();i++){
        
        kurang=false;
        if(inputAritmatika[i]=='-'){
            kurang=true;
            idx=i;
            do{
                i--;
            }while(isAngka(inputAritmatika[i-1]) && i>0);
            idxAwal=i;
            i=idx;

            do{
                i++;
            }while(isAngka(inputAritmatika[i+1]) && i<inputAritmatika.length()-1);
            idxAkhir=i;
            
            int j=idxAwal;
            while(j<idx){
                tempA+=inputAritmatika[j];
                j++;
            }

            j=idx+1;
            while(j<=idxAkhir){
                tempB+=inputAritmatika[j];
                j++;
            }
            
            //convert to int
            angkaA=stoi(tempA);
            angkaB=stoi(tempB);
            if(angkaMinus){
                sum=angkaA+angkaB;            
            }else{
                sum=angkaA-angkaB;
            }
            inputAritmatika.replace(idxAwal,idxAkhir-idxAwal+1, to_string(sum));
            break;
        }
    }
}

void pertambahan(){
       sum=0;
           tempA=""; tempB="";
	
	bool angkaMinus=false;

    int idx=0;
    for(int i=0;i<inputAritmatika.length();i++){
        tambah=false;
        if(inputAritmatika[i]=='+'){
            tambah=true;
            idx=i;
            do{
                i--;
				if(inputAritmatika[i-1]=='-'){
					i--;
					break;
				}
            }while(isAngka(inputAritmatika[i-1]) && i>0);
            idxAwal=i;
            i=idx;

            do{
                i++;
            }while(isAngka(inputAritmatika[i+1]) && i<inputAritmatika.length()-1);
            idxAkhir=i;
            
            int j=idxAwal;
            while(j<idx){
                tempA+=inputAritmatika[j];
                j++;
            }

            j=idx+1;
            while(j<=idxAkhir){
                tempB+=inputAritmatika[j];
                j++;
            }
            
            //convert to int
            angkaA=stoi(tempA);
            angkaB=stoi(tempB);
            sum=angkaA+angkaB;
            inputAritmatika.replace(idxAwal,idxAkhir-idxAwal+1, to_string(sum));
            break;
        }
    }
}

void pembagian(){
    sum=0;
        tempA=""; tempB="";
	bool angkaMinus=false;
    int idx=0;
    for(int i=0;i<inputAritmatika.length();i++){
        bagi=false;
        if(inputAritmatika[i]=='/'){
            bagi=true;
            idx=i;
            do{
                i--;
				if(inputAritmatika[i-1]=='-'){
					i--;
					break;
				}
            }while(isAngka(inputAritmatika[i-1]) && i>0);
            idxAwal=i;
            i=idx;

            do{
                i++;
            }while(isAngka(inputAritmatika[i+1]) && i<inputAritmatika.length()-1);
            idxAkhir=i;
            
            int j=idxAwal;
            while(j<idx){
                tempA+=inputAritmatika[j];
                j++;
            }

            j=idx+1;
            while(j<=idxAkhir){
                tempB+=inputAritmatika[j];
                j++;
            }
            
            //convert to int
            angkaA=stoi(tempA);
            angkaB=stoi(tempB);
            sum=angkaA/angkaB;
            inputAritmatika.replace(idxAwal,idxAkhir-idxAwal+1, to_string(sum));
            break;
        }
    }
}

void perkalian(){
    sum=0;
    tempA=""; tempB="";
    int idx=0;
	bool angkaMInus=false;
    for(int i=0;i<inputAritmatika.length();i++){
        kali=false;
        if(inputAritmatika[i]=='*'){
            kali=true;
            idx=i;
            do{
                i--;
				if(inputAritmatika[i-1]=='-'){
					i--;
					break;
				}
            }while(isAngka(inputAritmatika[i-1]) && i>0);
            idxAwal=i;
            i=idx;

            do{
                i++;
            }while(isAngka(inputAritmatika[i+1]) && i<inputAritmatika.length()-1);
            idxAkhir=i;
            
            int j=idxAwal;
            while(j<idx){
                tempA+=inputAritmatika[j];
                j++;
            }

            j=idx+1;
            while(j<=idxAkhir){
                tempB+=inputAritmatika[j];
                j++;
            }
            
            //convert to int
            angkaA=stoi(tempA);
            angkaB=stoi(tempB);
            sum=angkaA*angkaB;
            inputAritmatika.replace(idxAwal,idxAkhir-idxAwal+1, to_string(sum));
            break;
        }
    }
}
