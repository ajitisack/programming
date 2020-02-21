
x <- c(
 "ggplot2"
,"xgboost"
,"h2o"
,"plotly"
,"ggvis"
,"twitteR"
,"tm"
,"wordcloud"
,"quantmod"
,"smooth"
,"shiny"
,"shinydashboard"
,"DT"
,"h2o"
,"xgboost"
,"caret"
,"pROC"
,"dummies"
,"devtools"
,"data.table"
, "tidyr"
, "dplyr"
, "magrittr"
, "stringr"
, "lubridate"
, "bpa"
, "pryr"
, "bit64"
, "rmarkdown"
, "pander"
,"xlsx"
)

install.packages(x, dependencies = T, quiet = T)


x <- c(
          "tidyr"
        , "dplyr"
        , "magrittr"
        , "stringr"
        , "lubridate"
        , "bpa"
        , "pryr"
        , "bit64"
        , "rmarkdown"
        , "pander"
        ,"xlsx"
)

install.packages(x, dependencies = T, quiet = T)

devtools::install_github("wesm/feather/R")
