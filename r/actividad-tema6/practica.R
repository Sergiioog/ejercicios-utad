#install.packages("BSDA")
library(BSDA)
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
  mediaVisitas_poblacional <- 754 # ~ N(μ=754, σ)
  n_muestra1 <- 42
  x_muestral1 <- mean(nueva_landing$visitas)
  err_estandar1 <- sd(nueva_landing$visitas)/sqrt(n_muestra1) #Revisar cuando la desviacion tipica no se conoce

  #2 Planteamos la hipótesis
  
  # H0 : μ = 754
  # HA : μ > 754
  
  #Obtenemos por tanto, una hipótesis estadística unilateral a la derecha (>754)
  
  #3 Comprobamos la hipótesis
    
    #3.1 Calculamos el estadístico de contraste estandarizado observado (Zobs)
    zobs1 <- ((x_muestral1 - mediaVisitas_poblacional)/err_estandar1)

    #3.2 Calculamos el p-valor
    pvalor <- 1 - pnorm(zobs1)
    
    #3.3 Cálculo de la región crítica
    r_critica1Der <- (mediaVisitas_poblacional +qnorm(1-nivel_significacion) * err_estandar1)

    #3.4 Análisis extra: test para la media
    media1_test <- z.test(
      x = nueva_landing$visitas,                 
      sigma.x = sd(nueva_landing$visitas),       
      mu = mediaVisitas_poblacional,             
      alternative = "greater",                   
      conf.level = 0.95                           
    )
    print(media1_test)
    
    #3.5 Final: Resultado
    
    #Tras la resolución de las medidas estadísticas calculadas:
      # El pvalor1 = 0.054 > nivel significacion (0.05), por tanto NO RECHAZAMOS H0 
      # La región crítica a la derecha es = 769,48  y como la media comprobar es 769.09 por tanto, NO RECHAZAMOS H0 
      # El test de media dice, alternative hypothesis: true mean is greater than 754 (p-value > alfa), por tanto NO RECHAZAMOS H0 
      
      # Por tanto, concluimos, que no tenemos evidencia suficiente para decir que la media no sea mayor a 754
    
    
    
    

#2. Contrastar si la media de ventas diarias en la Landing B es mayor que la media de ventas diarias en
#la Landing A  
  
  landing_filtrada <- nueva_landing[!is.na(nueva_landing$ventas), ] #Filtro los datos de la landing ya que los NA entorpecen el calculo de medidas estadísticas

 
  

    
    
    
    
    
    
    
    
#3. Contrastar si la tasa de conversión en la Landing B es distinta que la tasa de conversión en la
#  Landing A
    
    #1 Escribimos los datos del problema (proporcion)
    p0TasaConversionA <- 0.18
    pTasaConversionB <- (sum(landing_filtrada$ventas) / sum(landing_filtrada$visitas))
    n <- sum(landing_filtrada$visitas) # n = suma de las visitas que han tenido ventas convertidas excluyendo los registros NA
    error_estandar <- sqrt((p0TasaConversionA*(1-p0TasaConversionA)/n))
    
    #2 Planteamos la hipótesis
    
    # H0 : tc = 0.18 (tasa conversion)
    # HA : tc != 0.18
    
    #Obtenemos por tanto, una hipótesis estadística bilateral (!= 0.18)
    
    #3 Comprobamos que el tamaño de la muestra es suficiente, a través del Teorema Central del Limite (para proporciones)
    
    res1 <- n*pTasaConversionB #3429 > 10 Correcto
    res2 <- n*(1-pTasaConversionB) #13843 > 10 Correcto
    
    #El tamaño de n es suficiente para realizar el análisis
    
    #3 Comprobamos la hipótesis
    
      #3.1 Calculamos el estadístico de contraste estandarizado observado (Zobs)
      #zobs3 <- (p-p0)/sqrt(p0*(1-p0)/n)
      zobs3 <- (pTasaConversionB - p0TasaConversionA)/error_estandar
    
      #3.2 Calculamos el p-valor
      pvalor3 <- 2 * (1 - pnorm(abs(zobs3)))
      
      #3.3 Cálculo de la región crítica
      #r_critica3 <- [(p0 -zalfa/2 * sqrt(p0*(1-p0)/n)),(p0 +zalfa/2 * sqrt(p0*(1-p0)/n))]
      z_alfa_2 <- qnorm(1 - nivel_significacion/2)
      r_critica3Izq <- (p0TasaConversionA -z_alfa_2 * error_estandar)
      r_critica3Der <- (p0TasaConversionA +z_alfa_2 * error_estandar)
      rCritica3Final <- c(r_critica3Izq,r_critica3Der) #Lo pongo en forma de vector para que sea "mas legible"
        
      #3.4 Análisis extra: test de proporciones
      prop3_test <- prop.test(
        x = sum(landing_filtrada$ventas),
        n = n,
        p = p0TasaConversionA,
        conf.level = 1 - nivel_significacion,
        alternative = "two.sided",  
        correct = FALSE             
      )
      print(prop3_test)
      
      #3.5 Final: Resultado
      
      #Tras la resolución de las medidas estadísticas calculadas:
        # El pvalor3 = 2.310^-10 < nivel significacion (0.05), por tanto RECHAZAMOS H0 EN FAVOR DE HA
        # La región crítica = [0.174, 0.185] y como la tasa de conv. a comprobar es 0.1985 entra en la zona de rechazo de H0, por tanto, RECHAZAMOS H0 en favor de HA
        # El test de proporciones dice, alternative hypothesis: true p is not equal to 0.18 (p-valor < alfa), por tanto RECHAZAMOS H0 en favor de HA
      
        #Concluimos diciendo que existe evidencia suficiente para determinar que la tasa de conversion es igual a 0,18
      
