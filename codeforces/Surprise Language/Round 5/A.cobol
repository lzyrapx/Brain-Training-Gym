       IDENTIFICATION DIVISION.
       PROGRAM-ID. SOLUTION.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 A        PIC 9(10)   VALUE ZEROES.
       01 B        PIC 9(10)   VALUE ZEROES.
       01 C      PIC z(10).
       Procedure division.
       Para-1.
       accept A
       accept B
       add A to B
       move B to C
       display C.
       End-para.
       Stop run.