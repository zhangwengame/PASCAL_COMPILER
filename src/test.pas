program ex;
    type
        arr = array[1..50] of integer;
        date = record
            year:1900..1999;
            month:1..12;
            day:1..31;
        end;
    
        age = 1..150;
    var
        i,a,b : integer;
        inta, intb, intc, intd : integer;
        t : boolean;
        aa:arr;
        dt:date;
        
        aage:age;
        achar:char;

    function testfunc(x:integer; y:integer):integer;
        var
            k,sum : integer;
        begin
            sum := 1;
            for k:=2 to x / 2 do
            begin
                if x mod k=0 then 
                    begin
                            sum := sum + k;
                    end;
            end;
                    testfunc := x + y; 
        end;
    function t(x:integer):boolean;
        begin
            
            writeln(x);
            t := x > 0;
        end;

    function perfect(x:integer):boolean;
        var
            k, sum : integer;
        begin
            sum := 1;
            for k:=2 to x / 2 do
            begin
                if (x mod k) = 0 then 
                    begin
                            sum := sum + k;
                    end;
            end;
            perfect := x=sum;
        end;
    begin

        a := 20 + 8;
        b := 30 + 700;
        i := (a + b) + 2 * (a + b);

        i := i - 3;
        
        writeln(i);

        i := b / 2;
        
        writeln(i);

        a := 3;
        i := (a + b);
        inta := intb + intc;
        intb := 2;
        intd := intb + intc;

        i := -3;
        
        if (i > 0) then 
        else if (i = 0) then 
        else 

        t := perfect(12);

        
        writeln(t);

        i := 3;
        
        writeln(i);

        i := testfunc(a, b);

        
        writeln(i);

        a := 30;
        b := 40;
        
    
        repeat
            
            writeln(a);
            
            writeln(b);
            a := a + 1;
        until (a > b);

        for a := 30 to 40 do
        begin
            
            writeln(a);
            a := a + 1;
        end;

        
        writeln(a);

        for a := 40 downto 30 do
        begin
            
            writeln(a);
            b := a + 1;
        end;

        
        repeat 
                readln(a);
                
                writeln(a);
                readln(b);
                
                writeln(b);
        until (a > 0) and (b > 0) and(a < b);


        

        for i:=a to b do
            if perfect(i) then writeln(i);

        a := 2;
        b := 3;

        case a of
            2: i := 3;
            5: i := 4;
            6:
                case b of
                    3: i := 6;
                    4: i := 7;
                end;
        end;

        
        writeln(i);

        a := 0;
        b := 10;


        while a <= 10 do
        begin
            b := b + 1;
            
            writeln(b);
            a := a + 1;
        end;
        
        writeln(b);

        
        for i:=1 to 50 do
            aa[i] := -i;

        writeln(aa[40]);

        for i := 50 downto aa[40] do
        begin
            write(aa[i]);
            
        end;

        dt.year := 2007;
        dt.month := 11;

        
        writeln(dt.year);
        
        writeln(dt.month);
        weekday := sun;
        if weekday = sun then 
        else 
        aage := 23;
        aage := 500;
        
        writeln(aage);
        i := -3;

        
        writeln(i);

        achar := 'a';
        achar := achar + 1;

        
        write(achar);

end.
