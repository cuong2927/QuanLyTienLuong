#include <iostream> 
#include <string>  
using namespace std; 

class NhanVien { 
    private: 
        string HoTen; 
        string maNV; 
        int namSinh; 
        int ngayVL;  
        int soNgayCong; 
        double luongCB; 
    public: 
    NhanVien() {
    	HoTen = "";
    	maNV = "";
    	namSinh = 0;
    	ngayVL = 0;
    	soNgayCong = 0;
    	luongCB = 0	;
	}
	NhanVien (string ht , string ma  , int ns , int nvl , int nc , double luong ){
		HoTen = ht;
		maNV = ma;
		namSinh = ns;
		ngayVL = nvl;
		soNgayCong = nc;
		luongCB = luong;
	}
	NhanVien (const NhanVien & nv){ 
	    HoTen = nv.HoTen;
	    maNV = nv.maNV;
	    namSinh = nv.namSinh;
	    ngayVL = nv.ngayVL;
	    soNgayCong = nv.soNgayCong;
	    luongCB = nv.luongCB;
	}
	virtual ~NhanVien (){}
	virtual void nhap ()  {
	    cin.ignore() ;
	    cout << "Nhap ho ten :";
	    getline (cin,HoTen);
	    cout << "Nhap ma nhan vien :";
	    getline (cin,maNV);
	    cout << "Nhap nam sinh :";
	    cin >> namSinh;
	    cout << "Nhap ngay vao lam :";
	    cin >> ngayVL;
	    cout << "Nhap so ngay cong :";
	    cin >> soNgayCong;
	    cout <<"Nhap luong co ban :";
	    cin >> luongCB;
	}
    virtual void xuat() const {
    	cout << "\n Ho ten :" << HoTen;
    	cout << "\n Ma nhan vien : " << maNV;
    	cout << "\n Nam sinh :" << namSinh;
    	cout << "\n Ngay vao lam :" << ngayVL;
   		cout <<"\n So ngay cong :" << soNgayCong;
   		cout <<"\n Luong :" << luongCB;	
		}
    virtual int loai() const = 0;
   	virtual double tongLuong() const = 0;
}; 

class NhanVienVanPhong : virtual public NhanVien { 
    protected: 
        string phongBan; 
        double heSoCV; 
        double gioLamThem; 
    public: 
        
	
		int loai() const  {return 1;}
}; 

class NhanVienKyThuat : virtual public NhanVien { 
    protected: 
        string chuyenNganh;
        int soSP; 
        int bacKN; 
    public: 
    NhanVienKyThuat () {
    	chuyenNganh = "";
    	soSP = 0;
    	bacKN = 0;
	}
	NhanVienKyThuat ( string ht  , string ma , int ns , int nvl , int nc  , double luong , string cn , int sp  , int kn )
	:	NhanVien(ht, ma, ns , nvl, nc, luong) , chuyenNganh(cn), soSP(sp) , bacKN(kn)
	{
		
	}
	NhanVienKyThuat (const NhanVienKyThuat & n) {
		chuyenNganh = n.chuyenNganh;
		soSP = n.soSP;
		bacKN = n.bacKN;
	}
	virtual ~ NhanVienKyThuat (){}
	
	 
    	int loai() const  {return 2;} 
};

class KySuQuanLy : public NhanVienVanPhong , public NhanVienKyThuat { 
    public: 
	
	 
		int loai() const  {return 3;}
}; 

//Day la phan cau 5 
template <class T> 
void hoanDoi(T a, T b) { 
	T temp = a; 
	a = b; 
	b = temp;
}


//Cau 6 
class PhongNhanSu { 
    private: 
        NhanVienVanPhong *ds;
    public: 


}; 

template <class T>
class DanhSach {
    private:  
        T *a;
        int soLuong; //so luong phan tu hien co 
        int sucChua; //suc chua toi da cua danh sach

        void resize() { 
            T *moi = new T[sucChua*2]; 
            for(int i=0;i<soLuong;i++) moi[i] = a[i]; 
            delete []a; 
            a=moi; 
            sucChua*=2; 
        }
        
    public:  
    	DanhSach(int sc = 10) :sucChua(sc), soLuong(0)  { 
    		a = new T[sucChua];
		} 
		~DanhSach() {  
			xoaHet();
			delete []a;
		} 
		DanhSach(const DanhSach<T> &b) { 
			for (int i=0;i<soLuong;i++) { 
				b[i] = a[i];
			}
		} 
		void them(T& b) { 
			if(soLuong==sucChua) resize(); 
			a[soLuong++] = b; 
			cout<<"Them thanh cong !\n"; 
			
		} 
		void hienThi() const { 
			for(int i=0;i<soLuong; i++) { 
				a[i]->xuat();
			}
		} 
		 
		double tongLuong() const { 
			double tong = 0.0;
			for(int i=0;i<soLuong;i++) { 
				tong+=a[i]->tongLuong();
			} 
			return tong;
		} 
		
		T luongNhoNhat() { 
			int min_index = 0; 
			for(int i=1 ;i<soLuong;i++) { 
				if(a[min_index]->tongLuong() > a[i]->tongLuong()) {	
					min_index = i;
				}
			} 
			return a[min_index];
		}
		
		int dem(int &l) { 
			int dem = 0; 
			for(int i=0;i<soLuong;i++) { 
				if(a[i]->loai() == l ) dem++;
			} 
			return dem;
		} 
		
		double trungBinhLuong(int &l) { 
			double tong = 0; 
			for(int i=0;i<soLuong;i++) { 
				if(a[i]->loai() == l ) tong+=a[i]->tongLuong(); 
			} 
			return (soLuong == 0) ? 0 : tong/soLuong;
		} 
		
		void sapXep() { 
			for(int i=0;i<soLuong-1;i++) { 
				int min_index = i; 
				for(int j = i+1 ;j<soLuong;j++) { 
					if(a[min_index]->tongLuong() < a[i]->tongLuong()) { 
						min_index = j;
					}
				} 
				if(min_index != i) { 
					hoanDoi(a[i],a[min_index]);
				}
			}
		} 
		
		void xoaHet() { 
			for(int i=0;i<soLuong;i++) { 
				delete a[i];
			} 
			soLuong=0;
		}
		
    

}; 


//cau 8 
void menuNhanSu() { 
    PhongNhanSu a;

}

void menuDS() { 
    DanhSach<NhanVien*> ds;

} 

int main() { 
    cout<<"Hello world"<<endl;

    return 0;
}
