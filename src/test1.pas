program ex_7;
	type
		arr = array[1..50] of integer;
		date = record
			year:1900..1999;
			month:1..12;
			day:1..31;
		end;
		days = (sun,mon,tue,wed,thu,fri,sat);
		colors = (red,yellow,blue,white,black,green);
		age = 1..150;
	var
		i,a,b : integer;
		inta, intb, intc, intd : integer;
		t : boolean;
		aa:arr;
		dt:date;
		color:colors;
		weekday:days;
		aage:age;
		achar:char;
begin
	weekday:=mon;
end.