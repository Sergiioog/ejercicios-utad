nueva_landing <- read.csv("C:/Users/sergi/OneDrive/INSO/2º CURSO/PROBABILIDAD Y ESTADÍSTICA/Entregables/Nueva carpeta/nueva_landing.csv")


#Los datos históricos de la Landing A son:
#• Número medio de visitas diarias a la landing del curso: 754
#• Número medio de ventas diarias: 135.72
#• Tasa de conversión (ventas/visitas): 0.18
mediaVisitas_poblacional <- 754
mediaVentas_poblacional <- 135.72
tasaConversion_poblacional <- 0.18
nivel_significacion <- 0.05


#Todos los contrastes se realizarán con un nivel de significación del 5%
#1. Contrastar si la media de visitas diarias en la Landing B es mayor que 
#la media de visitas diarias en la Landing A
 
  #1 Escribimos los datos del problema
  mediaVisitas_poblacional <- 754 # ~ N(μ=754, σ= 61.05)
  tamano_muestra1 <- 42
  media_muestral1 <- mean(nueva_landing$visitas)
  desv_tipica1 <- sd(nueva_landing$visitas)

  #2 Planteamos la hipótesis
  
  # H0 : μ = 754
  # HA : μ > 754
  
  #Obtenemos por tanto, una hipótesis estadística unilateral a la derecha (>754)
  
  #3 Comprobamos la hipótesis
    
    #3.1 Calculamos el estadístico de contraste estandarizado observado (Zobs)
    zobs1 <-  (media_muestral1 - mediaVisitas_poblacional)/(desv_tipica1/sqrt(tamano_muestra1))
    #qnorm(1-nivel_significacion)
    
    #3.2 Calculamos el p-valor
    pvalor <- pnorm(zobs1, lower.tail = FALSE)
    
    #3.3 Comprobamos con el nivel de significacion, cómo el pvalor es 0,054 > al nivel de signifi.
    # (0.05), NO rechazamos la hipotesis nula en favor de la alternativa, y por tanto no hay evidencia estadísticamente 
    # significativa de que la media de visitas en la Landing B sea mayor que 754.
    
    #3.4 Comprobación extra: Cálculo de la región crítica (derecha)
    z_alfa_medios <- qnorm(1-0.05)
    regioncriticaDer1 <- (mediaVisitas_poblacional + z_alfa_medios * (desv_tipica1/sqrt(tamano_muestra1)))
 
  
  
  
  
  