C     -*- fortran -*-
C     This file is autogenerated with f2py (version:2)
C     It contains Fortran 77 wrappers to fortran functions.

      subroutine f2pywrapsigma (sigmaf2pywrap, eps, e, linearity_m
     &at)
      external sigma
      double precision eps
      double precision e
      integer linearity_mat
      double precision sigmaf2pywrap, sigma
      sigmaf2pywrap = sigma(eps, e, linearity_mat)
      end


      subroutine f2pywrapsigmap (sigmapf2pywrap, eps, e, linearity
     &_mat)
      external sigmap
      double precision eps
      double precision e
      integer linearity_mat
      double precision sigmapf2pywrap, sigmap
      sigmapf2pywrap = sigmap(eps, e, linearity_mat)
      end

