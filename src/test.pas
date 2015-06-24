program a; 
var
i,j,z:integer;
a,b,c:real;
begin
a:=0.2;
writeln(a);
b:=-0.3;
writeln(b);
c:=a+b-0.001;
writeln(c);
c:=a*b;
writeln(c);
c:=a/b;
writeln(c);
if c<0.1 then
 writeln(123)
else
 writeln(0);

if c<=1.0 then
 writeln(321)
else
 writeln(111);

if c=-0.666667 then 
 writeln(666)
else 
begin
 writeln(111);
 writeln(999);
end;

i:=2;
writeln(i);
j:=-3;
writeln(j);
z:=i*j;
writeln(z);
z:=i mod j;
writeln(z);
end.
