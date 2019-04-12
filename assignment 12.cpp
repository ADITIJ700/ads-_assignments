
import     java.util.*;
class     student
{
static     int     div_no=1;//  static     instance     variable     it     have     global     sc  ope     for     all     objects
protected     int     rno;     //protected     instance     var  .
public     String     nm;//public     instance     var  .
double     per;
student  ()
{
rno=0;
nm="abc";
per=0.0;
}
}
class     scope     extends     student
{
private     String     addr;     //private     instance     var  .
scope  ()
{
addr="  xyz  ";
}
void     display(  scope  []     t,int     n)
{
for(int     i=0;i<n;i++)
{
System.out.print(t[i].rno);//accessing     instance     variable     of     currently     executing     object
System.out.print("\t"+t[i].div_no);
System.out.print("\t"+t[i].nm);
System.out.print("\t"+t[i].per);
System.out.print("\t"+t[i].addr);
System.out.println();
}
}
void     get  ()
{
Scanner     s=new     Scanner(System.in);
System.out.println("enter     rno     ");
rno=s.nextInt();
System.out.println("enter     name     ");
nm=s.next();
System.out.println("enter      percentage");
per=s.nextDouble();
System.out.println("enter     address");
addr=s.next();
}
public     static     void     main(String     args[])
{
int     n;//local     variable     for     main     function
System.out.println("enter     no     of     records");
Scanner     in=new     Scanner(System.in);
n=in.nextInt();
scope     s[]=new     scope  [n];//array     of     objects
scope     t=new     scope  ();
for(int     i=0;i<n;i++)//     local     scope     to     the     block     for     i
s[i]=new     scope  ();
for(int     i=0;i<n;i++)   
{                 
s[i].  get  ();
}
System.out.println("\nrno\tdiv\tname\tper\taddr\n");
/*for(int     i=0;i<n;i++)   
{                 
s[i].display();
System.out.println();
}
*/
t.display(s,n);
}
}
1/3
