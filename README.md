# 128-BIT-INTEGERS
A SET OF HEADERS USEFUL TO PERFORM INPUT AND OUTPUT OPERATIONS AND SOME USEFUL MATHEMATICAL FUNCTIONS FOR 128 BIT INTEGERS IN C/C++. FURTHER FUNCTIONALITIES MAY BE ADDED IN THE FUTURE AS NEEDED.


# OBSERVATION:

THE TOOM-COOK AND KARATSUBA MULTIPLICATION ALGORITHMS HERE PROVIDED MAY NOT YIELD THE CORRECT RESULT DEPENDING ON THE INPUT, IT VARIES ON HOW THE COMPILER HANDLE 128 BIT INTEGERS, IN INTERMEDIATE STEPS THESE ALGORITHMS CAN PRODUCE NEGATIVE NUMBERS. THESE ALGORITHMS IN FACT ARE OF PRACTICAL USE ONLY FOR VALUES ABOVE THOUSANDS DECIMAL DIGITS, WAY BIGGER THAN THE VALUES THAT CAN BE STORED ON A 128 BIT INTEGER, THERE'S A CONSIDERABLE OVERHEAD TO HANDLE SUCH 'SMALL' INTEGERS. BUT THE IMPLEMENTATIONS HERE PROVIDED ILLUSTRATE WELL THE MAIN STEPS OF THE ALGORITHM. FOR NUMBERS ABOVE THIS RANGE FAST FOURIER TRANSFORMATION (FFT) TECHNIQUES MUST BE USED INSTEAD. MOST INTEGER MULTIPRECISION LIBRARIES LIKE GMP INCLUDE EFFICIENT IMPLEMENTATIONS OF THESE TECHNIQUES.
