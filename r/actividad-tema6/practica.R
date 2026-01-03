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
 
  
#2. Contrastar si la media de ventas diarias en la Landing B es mayor que la media de ventas diarias en
#la Landing A  
  
  landing_filtrada <- nueva_landing[!is.na(nueva_landing$ventas), ] #Filtro los datos de la landing ya que los NA entorpecen el calculo de medidas estadísticas
  print(landing_filtrada)
  
  #1 Escribimos los datos del problema
  mediaVentas_poblacional <- 135.72
  tamano_muestra2<- 23
  media_muestral2 <- mean(landing_filtrada$ventas)
  desv_tipica2 <- sd(landing_filtrada$ventas)  
  
  #2 Planteamos la hipótesis
  
  # H0 : μ = 135.72
  # HA : μ > 135.72
  
  #Obtenemos por tanto, una hipótesis estadística unilateral a la derecha (>135.72)
  
  #3 Comprobamos la hipótesis
  
    #3.1 Calculamos el estadístico de contraste estandarizado observado (Zobs)
    tobs2 <-  (media_muestral2 - mediaVentas_poblacional)/(desv_tipica2/sqrt(tamano_muestra2))
    #qnorm(1-nivel_significacion)

        #3.2 Calculamos el p-valor
    pvalor2 <- pt(tobs2, df = n-1, lower.tail = FALSE)
    
    #3.3 Comprobamos con el nivel de significacion, cómo el pvalor es 0,025 < al nivel de signifi.
    # (0.05), SI rechazamos la hipotesis nula en favor de la alternativa, y por tanto hay evidencia estadísticamente 
    # significativa de que la media de ventas en la Landing B es mayor a 135.72.
    
    #3.4 Comprobación extra: Cálculo de la región crítica (derecha)
    z_alfa_medios2 <- qnorm(1-0.05)
    regioncriticaDer2 <- (mediaVentas_poblacional + z_alfa_medios * (desv_tipica2/sqrt(tamano_muestra2))) #Como la media muestral ≤ 146 → NO RECHAZO H₀
  
    
    resultado <- t.test(
      landing_filtrada$ventas,
      mu = 135.72,
      alternative = "greater",
      conf.level = 0.95
    )
   # print(resultado) REVISAR
    
  
    
    
    

    
    
    
    
    
    
    
    
#3. Contrastar si la tasa de conversión en la Landing B es distinta que la tasa de conversión en la
#  Landing A
    
    #1 Escribimos los datos del problema (es una proporcion)
    tasaConversion_poblacional <- 0.18
    tasa_conversion_b <- (sum(landing_filtrada$ventas) / sum(landing_filtrada$visitas))
    tamano_muestra <- 23
    error_estandar <- sqrt((0.18*(1-0.18)/tamano_muestra))
    
    #2 Planteamos la hipótesis
    
    # H0 : tc = 0.18
    # HA : tc != 0.18
    
    #Obtenemos por tanto, una hipótesis estadística bilateral
    
    #3 Comprobamos la hipótesis
    
      #3.1 Calculamos el estadístico de contraste estandarizado observado (Zobs)
      #zobs3 <- (p-p0)/sqrt(p0*(1-p0)/n)
      zobs3 <- (tasa_conversion_b - tasaConversion_poblacional)/sqrt(tasaConversion_poblacional*(1-tasaConversion_poblacional)/tamano_muestra)
    
      #3.2 Calculamos el p-valor
      pvalor3 <- 2 * pnorm(zobs3, lower.tail = FALSE)
        
      
      #COMPROBAR np0​≥5yn(1−p0​)≥5
      
      #3.3 Comprobamos con el nivel de significacion, cómo el pvalor es 0,81 > al nivel de signifi.
      # (0.05), NO rechazamos la hipotesis nula en favor de la alternativa, y por tanto NO hay evidencia estadísticamente 
      # significativa de que la tasa de conversión en la Landing B es distinta que la tasa de conversión en la
      #  Landing A
      
      #3.4 Comprobación extra: Cálculo de la región crítica (derecha)
      
    
    
    
    