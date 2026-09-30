package com.registro.api.entities;

import java.time.LocalDateTime;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.Table;

@Entity
@Table(name = "tb_registro_led")
public class RegistroLed {
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	Long id;
	
	@Column(name = "led_aceso")
	boolean ledAceso;
	
	@Column(name = "data_hora")
	LocalDateTime dataHora;

	public RegistroLed(boolean ledAceso, LocalDateTime dataHora) {
		this.ledAceso = ledAceso;
		this.dataHora = dataHora;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public boolean isLedAceso() {
		return ledAceso;
	}

	public void setLedAceso(boolean ledAceso) {
		this.ledAceso = ledAceso;
	}

	public LocalDateTime getDataHora() {
		return dataHora;
	}

	public void setDataHora(LocalDateTime dataHora) {
		this.dataHora = dataHora;
	}
	
	

	
}
