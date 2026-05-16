pub mod thyhappy_gui_render;

use winit;

#[derive(Default)]
struct ThyhappyApp {
    window: Option<Arc<winit::window::Window>>,
    renderer: Option<thyhappy_gui_render::ThyhappyGUIRenderer>
}

const DEFAULT_WINDOW_WIDTH: u32 = 800;
const DEFAULT_WINDOW_HEIGHT: u32 = 800;

impl winit::application::ApplicationHandler for ThyhappyApp {
    fn resumed(&mut self, event_loop: &winit::event_loop::ActiveEventLoop) {
        // Check if the window is already created
        if self.window.is_none() {
            // Create window
            {
                let window = winit::window::Window::default_attributes()
                    .with_title("hello")
                    .with_visible(true)
                    .with_inner_size(winit::dpi::LogicalSize::new(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT));


                // Create
                let window = event_loop.create_window(window).unwrap();

                // Pack it to Arc
                let window = Arc::new(window);

                // Init render work
                let thyhappy_gui_render = pollster::block_on(
                    thyhappy_gui_render::ThyhappyGUIRenderer::new(window.clone())
                    );

                // Save
                self.window = Some(window);
                self.renderer = Some(thyhappy_gui_render);
            }
        }

        // Request redraw window
        if let Some(window) = &self.window {
            window.request_redraw();
        }
    }

    fn window_event(&mut self, event_loop: &winit::event_loop::ActiveEventLoop,
                    _id:winit::window::WindowId,event:winit::event::WindowEvent) {
        // Window messages loop
        match event{
            // Do with exiting message
            winit::event::WindowEvent::CloseRequested => {
                // Tell caller the window should be closed
                let mut guard = SHOULD_CLOSE.write().unwrap();
                *guard = true;

                // Exit the window
                event_loop.exit();
            }

            // Do with painting message
            winit::event::WindowEvent::RedrawRequested => {
                // Check and render
                if let Some(renderer) = &mut self.renderer{
                    match renderer.render() {
                        Ok(_) => {
                            // If there is no any error, just do normal render work
                        }
                        Err(wgpu::SurfaceError::Lost) => {
                            // If lost the surface
                            // Rebuild it
                            // But I have not implemented the resize function
                            // So here are no any codes
                        }
                        Err(wgpu::SurfaceError::OutOfMemory) => {
                            event_loop.exit();
                        }
                        _=>{
                            // Default situation
                            // Maybe there is a bug
                            // Just give a tip
                            println!("Failed to render");
                        }
                    }
                }

                // Request next frame
                if let Some(window) = &self.window {
                    window.request_redraw();
                }
            }

            // Default
            _=>{}
        }
    }
}

fn run() {
    let event_loop = winit::event_loop::EventLoop::new().unwrap();
    let mut app = ThyhappyApp::default();

    event_loop.set_control_flow(winit::event_loop::ControlFlow::Poll);

    event_loop.run_app(&mut app).unwrap()
}

use std::sync::{Arc, RwLock};
use crate::thyhappy_gui_render::ThyhappyGUIRenderer;

static SHOULD_CLOSE: RwLock<bool> = RwLock::new(false);

pub fn initialize(){
    run();
}

pub fn window_should_close() -> bool{
    *SHOULD_CLOSE.read().unwrap()
}