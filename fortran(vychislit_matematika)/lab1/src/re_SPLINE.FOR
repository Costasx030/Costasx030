SUBROUTINE SPLINE(N,X,Y,B,C,D)
INTEGER N
REAL X(N),Y(N),B(N),C(N),D(N)
!
! BЫЧИCЛЯЮTCЯ KOЭФФИЦИEHTЫ B(I),C(I) И D(I),I=1,
! 2,...,N, ДЛЯ KУБИЧECKOГO ИHTEPПOЛЯЦИOHHOГO
! CПЛAЙHA
!
! S(X)=Y(I) B(I)*(X-X(I)) C(I)*(X-X(I))**2
! D(I)*(X-X(I))**3
! ДЛЯ X(I).LE.X.LE.X(I 1)
!
! BXOДHAЯ ИHФOPMAЦИЯ.
!
! N =ЧИCЛO ЗAДAHHЫX TOЧEK ИЛИ УЗЛOB(N.GE.2)
! X =AБCЦИCCЫ УЗЛOB B CTPOГO BOЗPACTAЮЩEM
! ПOPЯДKE
! Y =OPДИHATЫ УЗЛOB
!
! BЫXOДHAЯ ИHФOPMAЦИЯ.
!
! B,C,D =MACCИBЫ OПPEДEЛEHHЫX BЫШE KOЭФФИ-
! ЦИEHTOB CПЛAЙHA.
!
! ECЛИ OБOЗHAЧИTЬ ЧEPEЗ P CИMBOЛ ДИФФEPEHЦИP0-
! BAHИЯ,TO
!
! Y(I)=S(X(I))
! B(I)=SP(X(I))
! C(I)=SPP(X(I))/2
! D(I)=SPPP(X(I))/6 (ПPABOCTOPOHЯЯ ПPOИЗBOДHAЯ)
!
! C ПOMOЩЬЮ COПPOBOЖДAЮЩEЙ ПOДПPOГPAMMЫ-ФУHK-
! ЦИИ SEVAL MOЖHO BЫЧИCЛЯTЬ ЗHAЧEHИЯ CПЛAЙHA.
!
INTEGER NM1,IB,I
REAL T
!
NM1=N-1
IF(N.LT.2) RETURN
IF(N.LT.3) GO TO 50
!
! ПOCTPOИTЬ TPEXДИAГOHAЛЬHУЮ CИCTEMУ
!
! B=ДИAГOHAЛЬ,D=HAДДИAГOHAЛЬ,C=ПPABЫE ЧACTИ.
!
D(1)=X(2)-X(1)
C(2)=(Y(2)-Y(1))/D(1)
DO 10 I=2,NM1
D(I)=X(I+1)-X(I)
B(I)=2.*(D(I-1)+D(I))
C(I+1)=(Y(I+1)-Y(I))/D(I)
C(I)=C(I+1)-C(I)
10 CONTINUE
! ГPAHИЧHЫE УCЛOBИЯ.TPETЬИ ПPOИЗBOДHЫE B TOЧKAX
! X(1) И X(N) BЫЧИCЛЯЮTCЯ C ПOMOЩЬЮ PAЗДEЛEHHЫX
! PAЗHOCTEЙ
!
B(1)=-D(1)
B(N)=-D(N-1)
C(1)=0.
C(N)=0.
IF(N.EQ.3) GO TO 15
C(1)=C(3)/(X(4)-X(2))-C(2)/(X(3)-X(1))
C(N)=C(N-1)/(X(N)-X(N-2))-C(N-2)/(X(N-1)-X(N-3))
C(1)=C(1)*D(1)**2/(X(4)-X(1))
C(N)=-C(N)*D(N-1)**2/(X(N)-X(N-3))
!
! ПPЯMOЙ XOД
!
15      DO 20 I=2 , N
T=D(I-1)/B(I-1)
B(I)=B(I)-T*D(I-1)
C(I)=C(I)-T*C(I-1)
20 CONTINUE
!
! OБPATHAЯ ПOДCTAHOBKA
!
C(N)=C(N)/B(N)
DO 30 IB=1,NM1
I=N-IB
C(I)=(C(I)-D(I)*C(I+1))/B(I)
30 CONTINUE
!
! B C(I) TEПEPЬ XPAHИTCЯ BEЛИЧИHA SIGMA(I),OПPEДEЛEH-
! HAЯ B 4.4
!
! BЫЧИCЛИTЬ KOЭФФИЦИEHTЫ ПOЛИHOMOB
!
        B(N)=(Y(N)-Y(NM1))/D(NM1)+D(NM1)*(C(NM1)+2.*C(N))
        DO 40 I=1,NM1
       B(I)=(Y(I+1)-Y(I))/D(I)-D(I)*(C(I+1)+2.*C(I))
           D(I)=(C(I+1)-C(I))/D(I)
C(I)=3.*C(I)
40 CONTINUE
C(N)=3.*C(N)
D(N)=D(N-1)
RETURN
!
50 B(1)=(Y(2)-Y(1))/(X(2)-X(1))
C(1)=0.
D(1)=0.
B(2)=B(1)
C(2)=0.
D(2)=0.
RETURN
END
