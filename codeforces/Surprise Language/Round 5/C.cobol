      IDENTIFICATION DIVISION.
         PROGRAM-ID. SOLUTION.

         DATA DIVISION.
         WORKING-STORAGE SECTION.
         01 TXT      PIC X(11) VALUE SPACES.
         01 TMP      PIC X(11) VALUE SPACES.
         01 RES      PIC X(11) VALUE SPACES.
         01 RES2     PIC X(11) VALUE SPACES.
         01 K        PIC S9(10) VALUE ZEROES.
         01 I        PIC S9(10) VALUE ZEROES.
         01 CID      PIC S9(10) VALUE ZEROES.
         01 TMP2      PIC S9(10) VALUE ZEROES.
         01 CID2      PIC S9(10) VALUE ZEROES.

         PROCEDURE DIVISION.
           ACCEPT TXT
           ACCEPT TMP
           MOVE TMP TO K

           MOVE 1 TO I
           PERFORM UNTIL TXT(I:1) = ' '
             MOVE FUNCTION ORD(TXT(I:1)) TO CID
             SUBTRACT FUNCTION ORD("A") FROM CID
             ADD K TO CID
             DIVIDE CID BY 26 GIVING TMP2 REMAINDER CID2
             MOVE CID2 TO CID
             ADD FUNCTION ORD("A") TO CID

             STRING RES DELIMITED BY " ", FUNCTION CHAR(CID) INTO RES2
             MOVE RES2 TO RES

             ADD 1 TO I
           END-PERFORM
           DISPLAY RES
           STOP RUN.
