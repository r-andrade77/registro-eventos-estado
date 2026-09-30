package com.registro.api.controllers;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.registro.api.entities.RegistroLed;
import com.registro.api.service.RegistroLedService;

import jakarta.validation.Valid;

@RestController
@RequestMapping("/registros")
public class RegistroLedController {
	
	@Autowired
	private RegistroLedService service;
	
	@GetMapping
	public List<RegistroLed> listar(){
		List<RegistroLed> registros = service.listarTodos();
		return registros;
	}
	
	@PostMapping
	public RegistroLed salvar(@Valid @RequestBody RegistroLed registro) {
		RegistroLed registroSalvo = service.salvar(registro);
		return registroSalvo;
	}
	

}
