program test_f90
  use m_xoroshiro128plus

  type(rng_t) :: rng
  integer     :: i, dummy

  call rng%seed((/-1337_i8, 9812374_i8/))

  do i = 1, 1000*1000*1000
     dummy = rng%next()
  end do

  call rng%jump()

  print *, rng%next()
end program test_f90
