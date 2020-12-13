The operator overloading for the assignment operator is performed:

    - Video 160: Overloaded assingnment operator using copy
    - Video 161: Overloaded assingnment operator using MOVE (Using r-value references)

An example code to see how the assignment is done is performed.

The assignment operator could be overloaded:
    The assingment operator could only be used once the object is initialized.
    Eg.
	Case 1) Mystring s1;
	|     	Mystring s2 = s1; //Copy constructor would be called
	|		      	  // similar to=> Mystring s2 {s1}
	=====>	In Case 1) The assignment opearator is not called

	case 2) Mystring s1("s1");
	     	Mystring s2("s2");
		s2 = s1; // Overloaded assignment operator would be invoked now

The Overloaded opearator could also be used with temporary assignement:
    1) The deep copy using copy (Video 160)
    2) Shallow copy using move	(Video 161).

				  