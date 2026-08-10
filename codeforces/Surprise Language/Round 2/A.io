// https://github.com/IoLanguage/io
// https://iolanguage.org/repl/index.html

n := File standardInput readLine asNumber;
k := n;
while (n > 0,
	for (x, n, 1, -1,
		fl := 1;
		for (j, 2, x - 1,
			if (x % j == 0, fl := 0;);
		)
		if(fl == 1,
			n := n - x;
			x print;
			if(n > 0, "+" print);
			break;
		);
	);
);
"=" print;
k println;