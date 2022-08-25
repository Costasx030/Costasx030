!Для 0<=x<=2 с шагом h=0.2 вычислить значения функциии f(x) с использованием
!Программы QUANC8, где f(x) = integral{0,1} (e^xt) *sin(t)dt.
!По полученным точкам построить полином Лагранжа 10-й степени
!Сравнить значения сплайн-функции и полинома с точным значением
!f(x) (аналитически) в точках x(k)=(k - 0.5)h для k=1,2...10

program lab_1
   use Environment
implicit none 
   character(*), parameter    ::  output_file = "output.txt"
   integer                    ::  Out = 0
integer, parameter :: N = 11
   real(R_) :: spl=0, h = 0.2,  x = 0, low = 0, up = 0, abserr = 0, relerr = 0, resul = 0, errest, flag, Lx
   integer  :: nofun, i,k
   real(R_) :: Vf(N), Vx(N), B(N), C(N), D(N) 
   low = 0
   up = 1

   abserr = 0.000001
   relerr = 0.000001
   
   do i=1,N,1
      call QUANC8(fun,low, up, abserr, relerr, resul, errest, nofun, flag)
      write (*, "('f(x)=', f11.9, '   x =', f11.9)") resul, x
      Vx(i) = x
      Vf(i) = resul
      x = x + h
   end do
   write (*,"('-----------------------------------------')")
   do k=1,N-1,1
      x = (k - 0.5)*h
      call QUANC8(fun,low, up, abserr, relerr, resul, errest, nofun, flag)
      call lagrange(x,N,Lx)
      call SPLINE(N,Vx,Vf,B,C,D)
      spl=SEVAL(N,x,Vx,Vf,B,C,D)
!      print *, B(k), C(k), D(k), Vx(k), spl
 

   open (file=output_file, encoding=E_,position ='append',  newunit=Out) 
      write (out, "('\hline', f11.9,'  & ', f11.9, '  & ', f11.9, '  &  ', f11.9, ' \\ ')") x, resul, Lx, spl
   close (Out)
   
   end do

contains

   include 're_QUANC8.FOR'
   include 're_seval.FOR'
   include 're_SPLINE.FOR'
   
   real pure function fun(t) result(f)
        real,  intent (in)    :: t
          f = exp(x*t)*sin(t)
   end function fun 
  
     subroutine lagrange(x,N,Lx)  
      real, intent(in)  :: x
      integer, intent(in) :: N
      integer           :: l=0,m=0
      real              :: poly=0
      real, intent(out) :: Lx 
      
      Lx=0
      do l=1,N,1
      poly = 1
         do m=1,N,1
            if (l /= m) then
               poly = poly*((x-Vx(m))/(Vx(l)-Vx(m)))
             end if   
         end do
      Lx = Lx + Vf(l)*poly
      end do
      end subroutine lagrange
end program lab_1

