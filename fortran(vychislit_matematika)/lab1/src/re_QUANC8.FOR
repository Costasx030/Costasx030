
subroutine QUANC8(FUN,A,B,ABSERR,RELERR,RESULT,ERREST,NOFUN,FLAG)
!
      REAL FUN,A,B,ABSERR,RELERR,RESULT,ERREST,FLAG
      INTEGER NOFUN
!
!     OЦEHИTЬ ИHTEГPAЛ ДЛЯ FUN(X) OT A ДO B C ЗAДAHHOЙ
!     ПOЛЬЗOBATEЛEM TOЧHOCTЬЮ
!     ABTOMATИЧECKAЯ AДAПTИBHAЯ ПPOГPAMMA, OCHOBAHHAЯ HA
!     ФOPMУЛE HЬЮTOHA-KOTEЦA 8-OГO ПOPЯДKA
!
!     BXOДHAЯ ИHФOPMAЦИЯ
!
!    FUN    -ИMЯ BHEШHEЙ ФУHKЦИИ,PEAЛИЗУЮЩEЙ
!            BЫЧИCЛEHИE ПOДИHTEГPAЛЬHOЙ ФУHKЦИИ
!
!    A      -HИЖHИЙ  ПPEДEЛ ИHTEГPИPOBAHИЯ
!
!    B      -BEPXHИЙ ПPEДEЛ ИHTEГPИPOBAHИЯ (B MOЖET
!            БЫTЬ MEHЬШE, ЧEM  A)
!
!    RELERR -OTHOCИTEЛЬHAЯ ЖEЛAEMAЯ ПOГPEШHOCTЬ
!
!    ABSERR -AБCOЛЮTHAЯ ЖEЛAEMAЯ  ПOГPEШHOCTЬ
!
!    BЫXOДHAЯ ИHФOPMAЦИЯ
!
!    RESULT -ПPИБЛИЖEHHOE ЗHAЧEHИE ИHTEГPAЛA
!
!    ERREST -OЦEHKA BEЛИЧИHЫ ДEЙCTBИTEЛЬHOЙ OШИБKИ
!
!    NOFUN  -ЧИCЛO ЗHAЧEHИЙ ФУHKЦИИ,ИCПOЛЬЗOBAHHЫX
!            ПPИ BЫЧИCЛEHИИ ИHTEГPAЛA.
!
!    FLAG   -ИHДИKATOP HAДEЖHOCTИ. ECЛИ FLAG PABEH HУЛЮ,
!            TO RESULT УДOBЛETBOPЯET ЗAДAHHOЙ ГPAHИЦE
!            ПOГPEШHOCTИ. ECЛИ FLAG=XXX.YYY, TO  XXX-ЧИCЛO
!            ИHTEPBAЛOB ДЛЯ KOTOPЫX HE БЫЛO CXOДИMOCTИ,
!            A 0.YYY-ДOЛЯ OCHOBHOГO ИHTEPBAЛA, OCTABШAЯCЯ
!            ДЛЯ OБPAБOTKИ B TOT MOMEHT,KOГДA ПOДПPOГPAMMA
!            ПPИБЛИЗИЛACЬ K ПPEДEЛЬHOMУ ЧИCЛУ ДЛЯ NOFUN.
!
      REAL W0,W1,W2,W3,W4,AREA,X0,F0,STONE,STEP,COR11,TEMP
      REAL QPREV,QNOW,QDIFF,QLEFT,ESTERR,TOLERR
      REAL QRIGHT(31),F(16),X(16),FSAVE(8,30),XSAVE(8,30)
!
!     *** ЭTAП1 *** ПPИCBOEHИE HAЧAЛЬHЫX ЗHAЧEHИЙ
!     ПEPEMEHHЫM, HE ЗABИCЯЩИM OT ИHTEPBAЛA.
!     ГEHEPИPOBAHИE KOHCTAHT.
!
      INTEGER LEVMIN,LEVMAX,LEVOUT,NOMAX,NOFIN,LEV,NIM,I,J
      LEVMIN=1
      LEVMAX=30
      LEVOUT=6
      NOMAX=5000
      NOFIN=NOMAX-8*(LEVMAX-LEVOUT+2**(LEVOUT+1))
!
!     ECЛИ NOFUN ДOCTИГAET ЗHAЧEHИЯ NOFIN, TO TPEBOГA
!
      W0=3956.0/14175.0
      W1=23552.0/14175.0
      W2=-3712.0/14175.0
      W3=41984.0/14175.0
      W4=-18160.0/14175.0
!
!     ПPИCBOИTЬ HУЛEBЫE ЗHAЧEHИЯ ПEPEMEHHЫM CУMMAM
!
      FLAG=0.0
      RESULT=0.0
      COR11=0.0
      ERREST=0.0
      AREA=0.0
      NOFUN=0
      IF(A.EQ.B)RETURN
!
!     *** ЭTAП 2 *** ПPИCBOEHИE HAЧAЛЬHЫX ЗHAЧEHИЙ
!     ПEPEMEHHЫM, ЗABИCЯЩИM OT ИHTEPBAЛA, B
!     COOTBETCTBИИ C ПEPBЫM ИHTEPBAЛOM
!
      LEV=0
      NIM=1
      X0=A
      X(16)=B
      QPREV=0.0
      F0=FUN(X0)
      STONE=(B-A)/16.0
      X(8)=(X0+X(16))/2.0
      X(4)=(X0+X(8))/2.0
      X(12)=(X(8)+X(16))/2.0
      X(2)=(X0+X(4))/2.0
      X(6)=(X(4)+X(8))/2.0
      X(10)=(X(8)+X(12))/2.0
      X(14)=(X(12)+X(16))/2.0
      DO 25 J=2,16,2
      F(J)=FUN(X(J))
   25 CONTINUE
      NOFUN=9
!
!     *** ЭTAП 3 *** OCHOBHЫE BЫЧИCЛEHИЯ
!     TPEБУЮTCЯ QPREV, X0, X2, X4,...,X16, F0, F2, F4,...
!     ,F16. BЫЧИCЛЯЮTCЯ X1, X3,...,X15, F1, F3,...,F15,
!     QLEFT,QRIGHT,QNOW,QDIF,AREA
!
   30 X(1)=(X0+X(2))/2.0
      F(1)=FUN(X(1))
      DO 35 J=3,15,2
      X(J)=(X(J-1)+X(J+1))/2.0
      F(J)=FUN(X(J))
   35 CONTINUE
      NOFUN=NOFUN+8
      STEP=(X(16)-X0)/16.0
      QLEFT=(W0*(F0+F(8))+W1*(F(1)+F(7))+W2*(F(2)+F(6))+W3*(F(3)+F(5))+W4*F(4))*STEP
      QRIGHT(LEV+1)=(W0*(F(8)+F(16))+W1*(F(9)+F(15))+ W2*(F(10)+F(14))+W3*(F(11)+F(13))+W4*F(12))*STEP
      QNOW=QLEFT+QRIGHT(LEV+1)
      QDIFF=QNOW-QPREV
      AREA=AREA+QDIFF
!
!     *** ЭTAП 4 *** ПPOBEPKA CXOДИMOCTИ ДЛЯ ИHTEPBAЛA
!
      ESTERR=ABS(QDIFF)/1023.0
      TOLERR=AMAX1(ABSERR,RELERR*ABS(AREA))*(STEP/STONE)
      IF(LEV.LT.LEVMIN)GO TO 50
      IF(LEV.GE.LEVMAX)GO TO 62
      IF(NOFUN.GT.NOFIN)GO TO 60
      IF(ESTERR.LE.TOLERR)GO TO 70
!
!     *** ЭTAП 5 *** CXOДИMOCTИ HET.
!    УCTAHOBИTЬ CЛEДУЮЩИЙ ИHTEPBAЛ
!
   50 NIM=2*NIM
      LEV=LEV+1
!
!     ЗAПOMHИTЬ ЭЛEMEHTЫ, OTHOCЯЩИECЯ K ПPABOЙ ПOЛOBИHE
!     ИHTEPBAЛA, ДЛЯ БУДУЩEГO ИCПOЛЬЗOBAHИЯ.
!
      DO 52 I=1,8
      FSAVE(I,LEV)=F(I+8)
      XSAVE(I,LEV)=X(I+8)
   52 CONTINUE
!
!     COБPATЬ ЭЛEMEHTЫ, OTHOCЯЩИECЯ K ЛEBOЙ ПOЛOBИHE
!     ИHTEPBAЛA ДЛЯ HEMEДЛEHHOГO ИCПOЛЬЗOBAHИЯ
!
      QPREV=QLEFT
      DO 55 I=1,8
      J=-I
      F(2*J+18)=F(J+9)
      X(2*J+18)=X(J+9)
   55 CONTINUE
      GO TO 30
!
!     *** ЭTAП 6 *** "ПOЖAPHЫЙ" PAЗДEЛ
!     ЧИCЛO ЗHAЧEHИЙ ФУHKЦИИ БЛИЗKO K TOMУ, ЧTOБЫ
!     ПPEBЫCИTЬ УCTAHOBЛEHHЫЙ ПPEДEЛ.
!
   60 NOFIN=2*NOFIN
      LEVMAX=LEVOUT
      FLAG=FLAG+(B-X0)/(B-A)
      GO TO 70
!
!     TEKУЩEE ПPEДEЛЬHOE ЗHAЧEHИE ГЛУБИHЫ ДEЛEHИЯ
!     ПOПOЛAM PABHO LEVMAX
!
   62 FLAG=FLAG+1.0
!
!     *** ЭTAП 7 *** CXOДИMOCTЬ ДЛЯ ИHTEPBAЛA ИMEET MECTO
!     ПPИБABИTЬ OЧEPEДHЫE CЛAГAEMЫE K ПEPEMEHHЫM CУMMAM.
!
   70 RESULT=RESULT+QNOW
      ERREST=ERREST+ESTERR
      COR11=COR11+QDIFF/1023.0
!
!     УCTAHOBИTЬ CЛEДУЮЩИЙ ИHTEPBAЛ.
!
   72 IF(NIM.EQ.2*(NIM/2))GO TO 75
      NIM=NIM/2
      LEV=LEV-1
      GO TO 72
   75 NIM=NIM+1
      IF(LEV.LE.0)GO TO 80
!
!     COБPATЬ ЭЛEMEHTЫ, HEOБXOДИMЫE ДЛЯ CЛEДУЮЩEГO ИHTEBAЛA
!
      QPREV=QRIGHT(LEV)
      X0=X(16)
      F0=F(16)
      DO 78 I=1,8
      F(2*I)=FSAVE(I,LEV)
      X(2*I)=XSAVE(I,LEV)
   78 CONTINUE
      GO TO 30
!
!     *** ЭTAП 8 *** ЗAKЛЮЧИTEЛЬHЫE OПEPAЦИИ И BЫXOД
!
   80 RESULT=RESULT+COR11
!
!     OБECПEЧИTЬ, ЧTOБЫ ЗHAЧEHИE ПEPEMEHHOЙ ERREST
!     БЫЛO HE MEHЬШE УPOBHЯ OKPУГЛEHИЙ
!
      IF(ERREST.EQ.0.0)RETURN
   82 TEMP=ABS(RESULT)+ERREST
      IF(TEMP.NE.ABS(RESULT))RETURN
      ERREST=2.0*ERREST
      GO TO 82
      END
      
