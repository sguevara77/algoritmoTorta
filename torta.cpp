#include <iostream>
#include <set>
#include <string>


using namespace std;




struct node
{
	unsigned char d;
	unsigned char f;
	unsigned char c;
	unsigned char m;
	unsigned char count;
};


void traverse( node& n, std::string pie, std::set<std::string>& paths)
{
	if( n.count==9 )//es un Nodo final
	{
		if( pie[0]==pie[1] && pie[1]==pie[2] ||
			pie[3]==pie[4] && pie[4]==pie[5] ||
			pie[6]==pie[7] && pie[7]==pie[8] ||
			pie[0]==pie[3] && pie[3]==pie[6] ||
			pie[1]==pie[4] && pie[4]==pie[7] ||
			pie[2]==pie[5] && pie[5]==pie[8] )
			paths.insert(pie);
	    else if( n.m == 0 )//Se usó el comodin, se lo busca
		{
			std::string::size_type pos=pie.find("m");
			if( pos != std::string::npos )
			{
				std::string::size_type h_pos = pos % 3;
				if( h_pos == 0 && pie[pos+1]==pie[pos+2] )
					paths.insert(pie);
				if( h_pos == 1 && pie[pos-1]==pie[pos+1] )
					paths.insert(pie);
				if( h_pos == 2 && pie[pos-1]==pie[pos-2] )
					paths.insert(pie);
				else
				{
					std::string::size_type v_pos = pos / 3;
					if( v_pos == 0 && pie[pos+3]==pie[pos+6] )
						paths.insert(pie);
					if( v_pos == 1 && pie[pos-3]==pie[pos+3] )
						paths.insert(pie);
					if( v_pos == 2 && pie[pos-6]==pie[pos-3] )
						paths.insert(pie);
				}
			}
		}
		return;
	}
	else 
    {
        if( n.f>0)
	    {
		    node son=n;
		    son.f--;
            son.count++;
		    traverse(son, pie + "f",paths);
	    }
	    if( n.d>0)
	    {
		    node son=n;
		    son.d--;
            son.count++;
		    traverse(son, pie + "d",paths);
	    }
	    if( n.c>0)
	    {
		    node son=n;
		    son.c--;
            son.count++;
		    traverse(son, pie + "c",paths );
	    }
	    if( n.m >0 )
	    {
		    node son=n;
		    son.m--;
            son.count++;
		    traverse(son, pie + "m",paths );		
        }
    }
}

void calculate(std::set<std::string>& paths)
{
    
	node n;

	n.d=3;
	n.f=3;
	n.c=3;
	n.m=1;
	n.count=0;
	std::string pie;

	 
	
	traverse(n,pie,paths);
}

void main()
{
 std::set<std::string> paths;   
 calculate(paths);

 for( std::set<std::string>::iterator it=paths.begin();it!=paths.end();it++ )
 {
     std::string& pie(*it);
     std::cout << pie[0] << " " << pie[1] << " " << pie[2] << std::endl;
     std::cout << pie[3] << " " << pie[4] << " " << pie[5] << std::endl;
     std::cout << pie[6] << " " << pie[7] << " " <<  pie[8] << std::endl << std::endl;
 }

}
