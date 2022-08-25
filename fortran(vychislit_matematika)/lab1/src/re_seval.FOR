
        REAL FUNCTION SEVAL(N,U,X,Y,B,C,D)
      INTEGER N
      REAL U,X(N),Y(N),B(N),C(N),D(N)
!
!  ЭTA ПOДПPOГPAMMA BЫЧИCЛЯET ЗHAЧEHИE KУБИЧECKOГO
!  CПЛAЙHA
!
!  SEVAL=Y(I)+B(I)*(U-X(I))+C(I)*(U-X(I))**2+
!             D(I)*(U-X(I))**3
!
!  ГДE X(I).LT.U.LT.X(I+1). ИCПOЛЬЗУETCЯ CXEMA
!  ГOPHEPA
!
!  ECЛИ U.LT.X(1), TO БEPETCЯ ЗHAЧEHИE I=1.
!  ECЛИ U.GE.X(N), TO БEPETCЯ ЗHAЧEHИE I=N.
!
!  BXOДHAЯ ИHФOPMAЦИЯ.
!
!     N     -ЧИCЛO ЗAДAHHЫX TOЧEK
!     U     -AБCЦИCCA, ДЛЯ KOTOPOЙ BЫЧИCЛЯETCЯ ЗHAЧEHИE
!            CПЛAЙHA
!     X,Y   -MACCИBЫ ЗAДAHHЫX AБCЦИCC И OPДИHAT
!     B,C,D -MACCИBЫ KOЭФФИЦИEHTOB CПЛAЙHA, BЫЧИCЛEHHЫE
!            ПOДПPOГPAMMOЙ SPLINE
!
!  ECЛИ ПO CPABHEHИЮ C ПPEДЫДУЩИM BЫЗOBOM U HE
!  HAXOДИTCЯ B TOM ЖE ИHTEPBAЛE, TO ДЛЯ PAЗЫCKAHИЯ
!  HУЖHOГO ИHTEPBAЛA ПPИMEHЯETCЯ ДBOИЧHЫЙ ПOИCK.
!
      INTEGER I,J,K
      REAL DX
      DATA I/1/
      IF(I.GE.N) I=1
      IF(U.LT.X(I)) GO TO 10
      IF(U.LE.X(I+1)) GO TO 30
!
!  ДBOИЧHЫЙ ПOИCK
!
 10   I=1
      J=N+1
 20   K=(I+J)/2
      IF(U.LT.X(K))J=K
      IF(U.GE.X(K))I=K
      IF(J.GT.I+1)GO TO 20
!
!  BЫЧИCЛИTЬ CПЛAЙH
!
 30   DX=U-X(I)
      SEVAL=Y(I)+DX*(B(I)+DX*(C(I)+DX*D(I)))
      RETURN
      END
