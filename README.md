# xoroshiro128+ in Fortran

A Fortran 2008 translation of [xoroshiro128+](http://xoroshiro.di.unimi.it/).

## Compilation

    gfortran -O3 -flto -c m_xoroshiro128plus.f90

The test can then be compiled:

    gfortran -O3 -flto test_f90.f90 m_xoroshiro128plus.o -o test_f90

Using `gcc 5.3.1`, `-O3` and `-flto` are required to *inline* the code, to get
maximum performance.

## Usage example

    use m_xoroshiro128plus

    type(rng_t) :: rng

    ! Seed the random number generator
    call rng%seed((/1337_i8, 31337_i8/))

    print *, rng%next() ! A (signed) random 64-bit integer
    print *, rng%U01()  ! A double precision [0,1) float

## Performance

Generating 1 billion random numbers, using `gcc 5.3.1` and `-O3` on an i5 6600:

    C:       0.87 s
    Fortran: 1.07 s

## Notes

Because Fortran does not have unsigned integers, the constants have been
adjusted to their signed-integer equivalents.
