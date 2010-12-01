\name{nback1}
\alias{nback1}
\docType{data}
\title{Matrix of functional connectivity between 90 brain regions.}
\description{
       Correlation matrix of functional connectivity as measured by
       functional MRI for 90 brain regions, corresponding to the
       Automated Anatomical Labeling (AAL) template. This is the
       functional connectivity matrix of the first subject reported in
       Ginestet and Simmons (In press), under the 0-back condition. 
}
\usage{data(nback1)}
\format{This is a symmetric matrix object object of order 90 by 90. Both
  rows and columns are labeled with the adequate neuroanatomical names
  for the cortical and subcortical AAL regions.
}
\author{
  Cedric E Ginestet <c.ginestet05@gmail.com>
}
\source{
  
  Ginestet, C.E. and Simmons, A. (In Press). Statistical Parametric Network Analysis of Functional
  Connectivity Dynamics during a Working Memory Task. Neuroimage.

  Tzourio-Mazoyer, N.; Landeau, B.; Papathanassiou, D.; Crivello, F.;
  Etard, O.; Delcroix, N.; Mazoyer, B. & Joliot, M. (2002). Automated Anatomical
  Labeling of Activations in SPM Using a Macroscopic Anatomical
  Parcellation of the MNI MRI Single-Subject Brain. NeuroImage, 15,
  273-289
  
}
\examples{

data(nback1)
naHeatmap(nback1)
R <- metric.standardization(nback1)
cost.int.metric(R)

}
\keyword{datasets}
