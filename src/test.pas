program a; 
var
i,j,z:integer;
a,b,c:real;
ch:char;
begin
    a:=0.2;
    b:=-0.3;
    c:=a+b-0.001;
    writeln(c);
    ch:='a';
    c:=ch*b;
    writeln(c);	
    i:=21;	
    c:=a*i;
    writeln(c);
    c:=a/b;
    writeln(c);
    if c<1 then
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
