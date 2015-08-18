Pod::Spec.new do |s|
  s.name             = "Samba"
  s.version          = "0.1.0"
  s.summary          = "Swift availability check port for Objective-C"

  s.description      = <<-DESC
  Samba is a mini port for Swift 2.0 availability checking.
                       DESC

  s.homepage         = "https://github.com/skyweb07/Samba"
  # s.screenshots     = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "Oscar Antonio Duran Grillo" => "skyweb09@hotmail.es" }
  s.source           = { :git => "https://github.com/skyweb07/Samba.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/skyweb07'

  s.platform     = :ios, '7.0'
  s.requires_arc = true

  s.source_files = 'Pod/Classes/**/*'
  s.frameworks = 'UIKit', 'Foundation'
end
